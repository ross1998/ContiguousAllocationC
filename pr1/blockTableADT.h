
//Ross Martsenyak
//This is made and compiled in ubuntu 16.04 64bit (dualbooted instead of virtual machine)

#ifndef BLOCKTABLEADT_H
#define BLOCKTABLEADT_H

//typedef struct block_table *BlockTable;
//typedef int ItemType;

int** createArray(int rows);
void print2DArray(int** array, int rows);
void addBlocksToTable(int **array, int index, int blockSize, int fileSize);
int findSpace(int** array,int blocksNeeded, int rows);
void deleteBlocks(int** array, int index, int length);
void deleteBlockTable(int** array, int rows);

#endif