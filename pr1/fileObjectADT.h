
//Ross Martsenyak
//This is made and compiled in ubuntu 16.04 64bit (dualbooted instead of virtual machine)

#ifndef FILEOBJECTADT_H
#define FILEOBJECTADT_H

typedef struct file_object *FileObject;

FileObject createFile(char theName[30], int theSize, int theStart, int theLength);
void destroyFile(FileObject file);
void printFile(FileObject file);
int getSize();
char* getNameOfObject(FileObject file);
void deleteHelper(FileObject file, int **array);


#endif