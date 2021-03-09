/**
* Title : Algorithm Efficiency and Sorting
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 1
* Description : Function prototypes.
*/
void printArray(int *arr, int len);
void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount);
void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void hybridSort(int *arr, int size, int &compCount, int &moveCount);
void partition(int* theArray, int first, int last,
			int &pivotIndex, int& compCount, int& moveCount);
void performanceAnalysis();
