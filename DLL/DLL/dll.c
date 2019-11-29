#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "dllheader.h"

//temp code which is provided by UW

struct dll *dll_create(void){
    struct dll *thing = (struct dll*)malloc(sizeof(struct dll));
    thing -> head = NULL;
    
    //head = NULL;
    return thing;
 }

void deleteNode(struct dll *lst, struct dllnode *current)
{
    if(lst->head == current) {
        lst->head = current ->next;
    }
    if(current -> next != NULL)
    {
        current->next->prev = current->prev;
    }
    if(current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    free(current);
}

 struct dll *dll_destroy(struct dll* lst){
     struct dllnode *current = lst->head;
     while(current!=NULL)
     {
         struct dllnode *next = current->next;
         deleteNode(lst, current);
         current = next;
     }
     free(lst);
     lst = NULL;
     return lst;
     
 }
 void dll_add_item(struct dll* lst, int item){
     struct dllnode *newNode =(struct dllnode*)malloc(sizeof(struct dllnode));
     struct dllnode *temp = lst->head;
     newNode->item = item;
     newNode -> next = NULL;
     if(lst->head == NULL)
     {
         newNode -> prev = NULL;
         lst->head = newNode;
         return;
     }
     while(temp->next != NULL)
     {
         temp = temp->next;
     }
     temp->next = newNode;
     newNode->prev=temp;
     return;
     
 }

 bool dll_remove_item(struct dll* lst, int item){
     if(lst ==NULL) return false;
     struct dllnode *current = lst->head;
     struct dllnode *next;
     bool deleted=false;
     while(current != NULL)
     {
         if(current->item == item)
         {
             deleteNode(lst, current);
             deleted = true;
             break;
         }
         else {
             current = current -> next;
         }
     }
     if(deleted) return true;
     else return false;
     
 //YOUR CODE GOES HERE
 }
 struct dll *arr_to_dll(int *arr, size_t n){
     struct dll *thing = dll_create();
     for(int i=0;i<n;i++)
     {
         dll_add_item(thing,arr[i]);
     }
     return thing;
 }

/*int main(void){
    int a[] = {19,5,6,21,-2};
    struct dll *dlst = arr_to_dll(a, 5);
    assert(dll_remove_item(dlst,21));
    print_dll(dlst);
    dll_destroy(dlst);
}*/




