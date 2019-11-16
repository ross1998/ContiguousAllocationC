
//Ross Martsenyak
//This is made and compiled in ubuntu 16.04 64bit (dualbooted instead of virtual machine)

#include "fileObjectADT.h"
#include "blockTableADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct file_object {
    char nameFileObject[30];
    int sizeFileObject;
    int startIndexFileObject;
    int lengthFileObject;
};

FileObject createFile(char theName[], int theSize, int theStart, int theLength){ //Constructor for create FileObject
    FileObject ptr = malloc(sizeof(struct file_object));
    if(ptr != NULL){
        strcpy(ptr->nameFileObject, theName);
        ptr->sizeFileObject = theSize;
        ptr->startIndexFileObject = theStart;
        ptr->lengthFileObject = theLength;
    }
}


void destroyFile(FileObject file){ //For removing objects from blocks
    free(file);
}

void printFile(FileObject file){ //Prints Objects
    printf("%10s%10d%10d%10d\n", file->nameFileObject, file->sizeFileObject, file->startIndexFileObject, file-> lengthFileObject);
}

int getSize(){
    return sizeof(struct file_object);
}

char* getNameOfObject(FileObject file){
    return file->nameFileObject;
}

void deleteHelper(FileObject file, int **array){ //Delete Helper
    deleteBlocks(array, file->startIndexFileObject, file->lengthFileObject);
}