#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "dllheader.h"

//temp code which is provided by UW

struct dll *dll_create(void){
 struct llnode *head;
 //YOUR CODE GOES HERE
 }
 struct dll *dll_destroy(struct dll* lst){
 //YOUR CODE GOES HERE
 }
 void dll_add_item(struct dll* lst, int item){
 //YOUR CODE GOES HERE
 }
 bool dll_remove_item(struct dll* lst, int item){
 //YOUR CODE GOES HERE
 }
 struct dll *arr_to_dll(int *arr, size_t n){
 //YOUR CODE GOES HERE
 }

int main(void){
    int a[] = {19,5,6,21,-2};
    struct dll *dlst = arr_to_dll(a, 5);
    assert(dll_remove_item(dlst,21));
    print_dll(dlst);
    dll_destroy(dlst);
}




