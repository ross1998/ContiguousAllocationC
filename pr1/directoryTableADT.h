
//Ross Martsenyak
//This is made and compiled in ubuntu 16.04 64bit (dualbooted instead of virtual machine)

#ifndef DIRECTORYTABLEADT_H
#define DIRECTORYTABLEADT_H

#include "fileObjectADT.h"

typedef struct list_type *ListType;

ListType create(int elSize, int (*compare) (FileObject item1, char* item2));
void destroy(ListType listP);
void make_empty(ListType listP);
int is_empty(ListType listP);
int is_full(ListType listP);
int size_is(ListType listP);
void push(ListType listP, void *item);
void delete(ListType listptr, void *item, int **array);
void printl(ListType listP, void (*printItem) (FileObject item));



#endif