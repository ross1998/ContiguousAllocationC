
//Ross Martsenyak
//This is made and compiled in ubuntu 16.04 64bit (dualbooted instead of virtual machine)

#include <stdio.h>
#include <stdlib.h>
#include "blockTableADT.h"
#include "directoryTableADT.h"
#include "fileObjectADT.h"
#include <string.h>

//Method declarations
int askUserOptions();
void initiateUserChoice();
int figureOutBlocksNeeded(int blockSize, int fileSize);
int compare(FileObject, char*);
void printItem (FileObject p);


int main(void){ // Main
    
    //Fields 
    int storageDeviceSize;
    int blockSize;
    int userOption;
    int freeArrayIndex;

    //Procedures
    printf("Enter the size of your storage device: ");
    scanf("%d",&storageDeviceSize);
    printf("Enter the size of each block: ");
    scanf("%d",&blockSize);
    storageDeviceSize = (storageDeviceSize/blockSize);
    int** blockTable = createArray(storageDeviceSize);
    ListType directoryTableList;
    FileObject testFile;
    directoryTableList = create(getSize(), compare);
    userOption = askUserOptions();
    while(userOption != 4){ //While loop to be able to create ADT's in main() scope
        if(userOption == 1){ //Add a file
            char fileName[30];
            int fileSize;
            int theStartIndex;
            int blocksNeeded; 
            printf("Adding -enter filename:");
            scanf("%s", fileName);
            printf("Adding -enter file size:");
            scanf("%d", &fileSize);
            blocksNeeded = figureOutBlocksNeeded(blockSize, fileSize);
            theStartIndex = findSpace(blockTable, blocksNeeded, storageDeviceSize);
            if(theStartIndex != -1){
                testFile = createFile(fileName, fileSize, theStartIndex, blocksNeeded);
                addBlocksToTable(blockTable, theStartIndex, blockSize, fileSize);
                push(directoryTableList, testFile);
            }else{
                printf("Not enough consecutive space or your data is larger size than storage device! \n"); //Outlier case incase not enough room
            }
        }
        if(userOption == 2){ //Delete File
            char fileToDelete[30];
            printf("Deleting- enter a filename:\n");
            scanf("%s", fileToDelete);
            delete(directoryTableList, fileToDelete, blockTable);

        }
        if(userOption == 3){ //Print File
            printf("Printing- \n");
            printf("________________________________________________ \n");
            printf("Directory Table: \n");
            printf("%10s%10s%10s%10s\n", "FileName:", "Size:", "Start:", "Length:");
            printl(directoryTableList, printItem);
            printf("________________________________________________ \n");
            print2DArray(blockTable, storageDeviceSize);
        }
        userOption = askUserOptions();
    }
    destroy(directoryTableList);
    deleteBlockTable(blockTable, storageDeviceSize);
    free(blockTable);
    free(testFile);
    //free(directoryTableList);
    return 0;
}

int askUserOptions(){ //asks for user input for the 3 choices and returns as int
    int option;
    printf("Do you want to: \n");
    printf("Add a file? Enter 1 \n");
    printf("Delete a file? Enter 2 \n");
    printf("Print values? Enter 3 \n");
    printf("Quit? Enter 4 \n");
    scanf("%d",&option);
    return option;
}

int figureOutBlocksNeeded(int blockSize, int fileSize){ //self explanatory by title
    int tempFileSize = fileSize;
    int counter = 1;
    while(tempFileSize > blockSize){
        counter++;
        tempFileSize = tempFileSize - blockSize;
    }
    return counter;

}


int compare(FileObject a, char* b) { //Helper
   int toReturn = 1;
   toReturn = strcmp(getNameOfObject(a) , b);
   return toReturn;
}

void printItem (FileObject p) { //Helper
   printFile(p);
}
