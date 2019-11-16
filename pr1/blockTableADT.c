
//Ross Martsenyak
//Yeah I know this ADT is kinda useless since it doesnt use a struct.
//This is made and compiled in ubuntu 16.04 64bit (dualbooted instead of virtual machine)

#include "blockTableADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **createArray(int rows){ //Allocates a 2D array that is 2 cloumns and size rows
  int i;
  int **array = (int **)malloc(rows * sizeof(int *));
  for(int i = 0; i <rows; i++){                            //Submission
    array[i] = (int *)calloc(2, sizeof(int));
  }
  return array;
}

//The findSpace function is not working correctley when looking at the last index. Needs fixing.
int findSpace(int** array,int blocksNeeded, int rows){ //returns index of array that has enough consecutive spots to fit blocks needed
  int counter=0;
  //int columns = 2;
  int j;
  //printf("%d", rows);
  if (blocksNeeded > rows){
    printf("blocksNeeded: %d \n", blocksNeeded);
    printf("SizeOfStorage: %d \n", rows);
    return -1;
  }
  for( j = 0; j <= rows-blocksNeeded; j++ ){ //might need to delete the -1
      if((array[j][0] + array[j][1]) == 0){
        counter++;
      } else {
        counter = counter - counter; //resets counter when consecutive empty spaces get interrupted
      }
      if(counter == blocksNeeded){
        return j - (counter-1);
      }
  }
  return -1;
}

void addBlocksToTable(int **array, int index, int blockSize, int fileSize){ //Adds blocks to table
  int theFileSize = fileSize;
  int j = index;
  while(theFileSize >= blockSize){
    array[j][0] = blockSize;
    j++;
    theFileSize = theFileSize-blockSize;
  }
    array[j][0] = theFileSize;      //Submission
  if(theFileSize != 0){
  array[j][1] = blockSize-theFileSize;
  }
}


void print2DArray(int **array, int rows){ //Prints the 2D array out buy iterating through double for loop
  int columns = 2;
  int i;
    int j;
    printf("Block Table: \n");
    printf("%d \n",rows);
    printf("%10s%15s%15s\n", "Block Number:", "Size Used:", "Fragmented:");
    for( j = 0; j <= rows-1; j++ ){
        for( i = 0; i <= columns-1; i ++){
          if(i==0){
            printf("%1d", j);
          }
          printf("%20d" ,array[j][i]);
          printf("%5s", "");
        }
        printf( "\n" );
    }
}

void deleteBlocks(int** array, int index, int length){ //Deletes Blocks in graph to make them zeros
  int j;
  int i;
  for( i = 0; i <= 1;i++ ){
    for( j = index; j <= length+1; j++ ){
      array[j][i] = 0;
    }
  }
}

void deleteBlockTable(int** array, int rows){ //deallocate from memory
  int j = rows;
  int i = 0;
  for( i = 0; i <= j-1; i ++){
      free(array[i]);
  }
}