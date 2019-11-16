
pr1.out: driver.o directoryTableADT.o blockTableADT.o fileObjectADT.o
	gcc -o pr1.out driver.o directoryTableADT.o blockTableADT.o fileObjectADT.o

driver.o: driver.c blockTableADT.h directoryTableADT.h fileObjectADT.h
	gcc -c driver.c

blockTableADT.o: blockTableADT.c blockTableADT.h
	gcc -c blockTableADT.c

directoryTableADT.o: directoryTableADT.c directoryTableADT.h
	gcc -c directoryTableADT.c

fileObjectADT.o: fileObjectADT.c fileObjectADT.h
	gcc -c fileObjectADT.c