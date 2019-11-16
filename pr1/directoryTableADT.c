
//Ross Martsenyak
//This is made and compiled in ubuntu 16.04 64bit (dualbooted instead of virtual machine)
//This code is based off of your ADT List Generic provided on canvas

#include "directoryTableADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fileObjectADT.h"
#include "blockTableADT.h"


struct list_type {
  void *data;
  int size;
  int capacity;
  int elementSize;
  int (*comparePtr) (FileObject d1, char *d2);
};


// returns the pointer to the list; NULL if list not created
ListType create(int elSize, int (*comp) (FileObject item1,char* item2)) {
  // allocate memory for a structure variable containing all
  // list components
  ListType listptr = malloc(sizeof(struct list_type));
  // if allocation was succesfull
  if (listptr != NULL) {
     listptr->size = 0;
     listptr->capacity = 10;
     listptr->elementSize = elSize;
     listptr->comparePtr = comp;;
     //listptr->destroyPtr = destroy;
     // allocate memory for the actual array
     listptr->data = malloc(10*(listptr->elementSize));
     // if array not created, deallocate the list too
     if (listptr->data == NULL) {
       free(listptr);
       listptr = NULL;
     } 
  }
  return listptr;
}

void destroy(ListType listptr) {
  free(listptr->data);
  free(listptr);
  listptr = NULL;
}

void printl(ListType listptr, void (*printItem) (FileObject d)) {
  int i;
  for(i = 0; i < listptr->size; i++) {
    printItem(listptr->data + i * (listptr->elementSize) );

  }
  printf("\n"); 
}
int size_is(ListType listptr) {
   return listptr->size;
}

int is_empty(ListType listptr) {
   return listptr->size == 0;
}

void make_empty(ListType listptr) {
  // if list is larger than 200 elements, create a smaller one
  if (listptr->size > 200)
    listptr->data = realloc(listptr->data, listptr->elementSize * 100);
  
   listptr->size = 0;
   listptr->capacity = 100;
}


// adds a component to the array, if enough memory available
void push(ListType listptr, void *item) {
  if (listptr->size >= listptr->capacity) {
    void *temp = realloc(listptr->data, listptr->elementSize * (listptr->capacity + 100));
    if (temp != NULL) {
      listptr->capacity += 100;
      listptr->data = temp;
      memcpy(listptr->data + (listptr->size) * (listptr->elementSize), item, (listptr->elementSize));
      listptr->size++;
     }
   }
   else {
     memcpy(listptr->data + (listptr->size) * (listptr->elementSize), item, (listptr->elementSize));
     listptr->size++;
   }
}

int is_full(ListType listptr) {
  if (listptr->size >= listptr->capacity) {
      void * temp = malloc(listptr->elementSize* (listptr->capacity + 100));
   if (temp != NULL) {
	free(temp);
	return 0; 
   }
   else
     return 1;
   }
   return 0;
}

void delete(ListType listptr, void *item, int **array) { //Part of chain delete methods

   int idx = -1, i;

   for (i = 0; i < listptr->size; i++ ) {
	if (listptr->comparePtr(listptr->data + (i * listptr->elementSize), item) == 0) {
		idx = i;
		break;
	}
   }
  //printf("\n%d\n", idx);
  deleteHelper(listptr->data + i * (listptr->elementSize), array);
   if (idx >= 0) {
	memmove(listptr->data + (idx * listptr->elementSize),  listptr->data + (idx + 1) * listptr->elementSize, (listptr->size - idx - 1) * listptr->elementSize);
        (listptr->size)--;
   }

}
