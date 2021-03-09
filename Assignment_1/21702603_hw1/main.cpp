/**
* Title : Algorithm Efficiency and Sorting
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 1
* Description : Main program that creates
*               3 identical arrays and sorts with
*               different sorting algorithms.
*/

#include <iostream>
#include "sorting.h"
#include <cmath>
using namespace std;

int main() {

    int compCount, moveCount;

    int arr1[] = {20, 1, 100, 57, 92, 43, 99, 93, 17, 58};
    int arr2[] = {20, 1, 100, 57, 92, 43, 99, 93, 17, 58};
    int arr3[] = {20, 1, 100, 57, 92, 43, 99, 93, 17, 58};


    quickSort(arr1,0,9, compCount, moveCount);
    printArray(arr1, 10);

    insertionSort(arr2, 10, compCount, moveCount);
    printArray(arr2, 10);

    hybridSort(arr3, 10, compCount, moveCount);
    printArray(arr3, 10);


    performanceAnalysis();
    return 0;
}
