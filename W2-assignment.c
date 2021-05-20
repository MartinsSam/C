#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


typedef enum month{january, february, march, april, may, june, july, august, september, october, november,december} month;

typedef struct date {month m; int d;}date;

/*function responsible to calculate the next day and month - if needed*/
void get_next_day_month(struct date *current_date, bool end_of_month){
	//if end_of_month increment month and set day o 1
	if (end_of_month){
		current_date->d = 1;
		current_date->m = (current_date->m+1)%12;
	}else{
		//only increment the day
		current_date->d +=1;
	}
}

/*this function is going to guarantee that the program understand January as JANUARY*/
void to_lower_case(char * str){
	int i = 0;
	while(str[i]){
		str[i] = tolower(str[i]);
		i++;
	}
	//printf("result test %s\n", str);

}

int get_month_number_from_full_month_name(char *month){
	int month_number =-1;	
	to_lower_case(month);
	if (strcmp(month,"january") == 0){
		month_number = 0;
	}else if(strcmp(month,"february") == 0){
		month_number = 1;
	}else if(strcmp(month,"march") == 0){
		month_number = 2;
	}else if(strcmp(month,"april") == 0){
		month_number = 3;
	}else if(strcmp(month,"may") == 0){
		month_number = 4;
	}else if(strcmp(month,"june") == 0){
		month_number = 5;
	}else if(strcmp(month,"july") == 0){
		month_number = 6;
	}else if(strcmp(month,"august") == 0){
		month_number = 7;
	}else if(strcmp(month,"september") == 0){
		month_number = 8;
	}else if(strcmp(month,"october") == 0){
		month_number = 9;
	}else if(strcmp(month,"november") == 0){
		month_number = 10;
	}else if(strcmp(month,"december") == 0){
		month_number = 11;
	}else {
		printf("invalid month input (%s)", month);
	}

	return month_number;
}

void get_month_from_number(enum month month, char *str_month){
	
	//printf("received month %d\n", month);
	switch(month){
		case 0: strcpy(str_month,"Jan"); break;
		case 1: strcpy(str_month,"Feb"); break;
		case 2: strcpy(str_month,"Mar"); break;
		case 4: strcpy(str_month,"Apr"); break;
		case 5: strcpy(str_month,"May"); break;
		case 6: strcpy(str_month,"Jun"); break;
		case 7: strcpy(str_month,"Ago"); break;
		case 8: strcpy(str_month,"Sep"); break;
		case 9: strcpy(str_month,"Oct"); break;
		case 10: strcpy(str_month,"Nov"); break;
		case 11: strcpy(str_month,"Dec"); break;
	}
}

void get_result(struct date *current_date, char *str_month){
	
	//0 means january - 6 means july
	//7 means august - 11 means december
	
	if (current_date->m == 1){//february
		if(current_date->d >= 28){

			printf("\nFor february is considered 28 days only\n");
			get_next_day_month(current_date, true);
		
		}
	}
	else{
		//identify months between jan up jul
		if(current_date->m <=6 && current_date->m%2 ==0 && current_date->d == 31){
			printf("it should be a new month %d", current_date->m +1);
			get_next_day_month(current_date, true);

		}//identify months between ago up to dec
		else if(current_date->m >=7 && current_date->m%2 ==1 && current_date->d == 31){
			get_next_day_month(current_date, true);
		}//get months with 31 days
		else if(current_date->d ==30){
			get_next_day_month(current_date, true);
		}
		//is not a month change
		else{
			get_next_day_month(current_date, false);
		}
	}

	//printf("\nResult Month:%d\tDay:%d\n", current_date->m, current_date->d);
	get_month_from_number(current_date->m,str_month);
	printf("%s %d\n\n", str_month,current_date->d);
}
int main(){
	date date_struct;//struct date
	date *date_ptr = &date_struct;//pointer to the struct

	/*temporary variables to get the input from date*/
	char month[10];
	char *str_ptr = month;


	int day;

	//ask the date for the user, expecting: 'long month name' day
	printf("Type month day:");
	scanf("%s %d", &month, &day);
	
	
	date_ptr->d = day;
	date_ptr->m = get_month_number_from_full_month_name(str_ptr);

	//printf("day: %d month: %d\n", date_ptr->d, date_ptr->m);

	get_result(date_ptr, str_ptr);
	//get_month_from_number(date_ptr);
	
	return 0;
}	

