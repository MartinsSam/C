#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//create a struct to keed the list data
typedef struct node{
        int data;
        struct node *next;
}node;


//funtion to prepare a new space and fill the struct data 
node *add_element_in_the_list(int d){
        node *head = malloc(sizeof(node));
        head -> data = d;
        head -> next = NULL;
        return head;
}

//add elements in the list
node *add_to_front(int d, node*h){
        node *head = add_element_in_the_list(d);
        head ->next = h;
        return head;
}

//from random values, fill the list
//the random list will be up to the number of the size, i.e if the size is 10 the random number will be between 0 and 10
node* fill_the_list(int size){
        node *head = add_element_in_the_list(rand()% size);
        int i;
        for(i = 0; i < (size-1);i++){
                head = add_to_front(rand()%size+1, head);
        }
        return head;
}
//use bubble sort for algorithm 
void bubbleSort(node *first_node, int size){
        bool swap=false;
        node *current_nd;
        node *next_nd;
        //start from size - 2 position, considering that in 
        for (int i = size -2; i >=0; i--){
                //printf("i value %d\n ", i);
                //get current node and next node 
                current_nd = first_node;
                next_nd = current_nd->next;

                for (int j = 0; j <= i; j++){
                        //printf("\tj value %d\n", j);
                        //printf("\t\t current_nd->data = %d \t next_nd->data = %d\n", current_nd->data, next_nd->data);
                        //compare the data in both nodes, if current greater than next, switch the data information
                        if(current_nd ->data > next_nd->data){
                                int swap_value = current_nd->data;
                                current_nd->data = next_nd->data;
                                next_nd->data = swap_value;
                                //change the swap value to true
                                swap = true;
                        }
                        current_nd = next_nd;
                        next_nd = next_nd->next;
                }
                //if during this for the swap result is false it means there the list is already sorted and don't need to keep the execution
                if(!swap){
                        break;
                }
        }

}
void print_list(node *h, char *title){
        printf("%s\n", title);
        int count = 0;
        while(h != NULL){
                printf("%d\t", h->data);
                h = h -> next;
                count +=1;
                if(count > 4){
                        printf("\n");
                        count = 0;
                }
        }
}


int main(void){
        int size = 100;
        /*
        for(int i = 0;i < 99; i++){
                printf("%d\n", rand()%100);
        }*/

        //declare the struct
        node random_list;
        //pointer to 
        node *random_list_ptr;
        //populate the list with random values
        random_list_ptr = fill_the_list(size);
        print_list(random_list_ptr, "original list");
                                                        
        printf("\n\n");
        return 0;
}

