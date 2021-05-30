#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Open the file, get the first position information and update the size information to be used by array

void get_array_size(FILE *ptr, int *ptr_size){
	//position the pointer to the file beginning
	rewind(ptr);

	//get first number to use it as array size
	fscanf(ptr, "%d",ptr_size);
}
/*
function purpose: 
	Get the data and add it in the data array
	Respect the size defined in the first element in array. 
		If the file has more elements than defined in first position, gets only n first elements
*/
void read_data(FILE *ptr, int d[], int *size){
	int expected_size = *size, current_size = 0;
	*size = 0;

	//the while starts from second element
	while(current_size < expected_size && fscanf(ptr, "%d",&d[*size]) == 1){
		(*size)++;
		current_size++;
	}
}

void print_data(int d[], int size, FILE *ofp){
	int i;
	for(i = 0; i < size; i++){
		printf("%d\t", d[i]);
		fprintf(ofp,"%d\t", d[i]);
		if ((i +1) % 10 == 0){
			printf("\n");
			fprintf(ofp,"\n");
		}
	}
}

double average(int d[], int size){
	int i;
	double avg = 0.0;
	for (i=0; i< size; i++){
		avg +=d[i];
	}
	return (avg/size);
}

int get_maximum(int d[], int size){
	//starts max with first element if the array 
	int max = d[0];
	//starts for in second element
	for (int i=1; i< size; i++){
		//if this element is greater than previous element, update max var;
		if(d[i] > max){
			max = d[i];
		}
	}
	return max;
}


//check if array is empty, it will warn the program to break
bool isArrayEmpty(int size){
	if(size == 0){
		return true;
	}
	return false;
}
int main(){
	int size_info_from_file;
	int *ptr_size = &size_info_from_file;

	FILE *ifp, *ofp;

	ifp = fopen("answer-hw3_input.txt", "r");
	ofp = fopen("answer-hw3.txt", "w");
	get_array_size(ifp,ptr_size);
	//printf("\nSize information that I got %d\n", size_info_from_file);
	
	//if first value got is 0, exit the program.
	if (isArrayEmpty(size_info_from_file)){
		exit(1);
	}

	int get_data_info[size_info_from_file];

	read_data(ifp, get_data_info, &size_info_from_file);

	print_data(get_data_info, size_info_from_file,ofp);
	printf("\n");
	printf("\n average score was %.2f", average(get_data_info,size_info_from_file));
	printf("\n maximum number defined was %d", get_maximum(get_data_info,size_info_from_file));
	printf("\n\n");
	
	//file print

	fprintf(ofp,"\n\n average score was %.2f\n", average(get_data_info,size_info_from_file));
	fprintf(ofp,"\n maximum number defined was %d", get_maximum(get_data_info,size_info_from_file));

	fclose(ifp);
	fclose(ofp);
	return 0;

}