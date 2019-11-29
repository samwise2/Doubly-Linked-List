#include <stdio.h>
#ifndef DLLHEADER
#define DLLHEADER

struct dllnode{
  int item;
  struct dllnode *next;
  struct dllnode *prev;
};

struct dll{
  struct dllnode *head;
};

struct dll *dll_create(void);
struct dll *dll_destroy(struct dll* lst);
void dll_add_item(struct dll* lst, int item);
bool dll_remove_item(struct dll* lst, int item);
struct dll *arr_to_dll(int *arr, size_t n);

void print_dll(struct dll *lst){
  struct dllnode *next_node = lst->head;
  struct dllnode *prev_node = NULL;
  printf("Doubly Linked List: ");
  while(next_node){
    printf("%d ", next_node->item);
    prev_node = next_node;
    next_node = next_node->next;
    if(next_node) printf("-> ");
  }
  printf("\n");
  printf("Reversed:");
  while(prev_node){
    printf("%d ", prev_node->item);
    prev_node = prev_node->prev;
    if(prev_node) printf("<- ");
  }
  printf("\n");
}

#endif
