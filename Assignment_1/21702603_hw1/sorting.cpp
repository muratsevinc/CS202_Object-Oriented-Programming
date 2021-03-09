/**
* Title : Algorithm Efficiency and Sorting
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 1
* Description : Sorting algorithm bodies.
*/

#include "sorting.h"
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;
void printArray(int *arr, int len){
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

void partition(int* theArray, int first, int last,
			int &pivotIndex, int& compCount, int& moveCount) {

   int pivot = theArray[first]; // copy pivot
   moveCount++;
       // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {

      compCount++;
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
    	  moveCount = moveCount + 3;
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   moveCount = moveCount + 3;
   pivotIndex = lastS1;
}


void quickSort(int* arr, int first, int last, int& compCount, int& moveCount) {
	int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(arr, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quickSort(arr, first, pivotIndex-1,compCount, moveCount);
      quickSort(arr, pivotIndex+1, last, compCount, moveCount);
   }
}

void hybridPartition(int* theArray, int first, int last, int &pivotIndex, int& compCount, int& moveCount){
    if ((last - first ) > 10){// quick sort part

        int pivot = theArray[first];
        moveCount++;
        int lastS1 = first;
        int firstUnknown = first + 1;

       for (  ; firstUnknown <= last; ++firstUnknown) {

          compCount++;
          if (theArray[firstUnknown] < pivot) {  	// belongs to S1
              ++lastS1;
              swap(theArray[firstUnknown], theArray[lastS1]);
              moveCount = moveCount + 3;
          }	// else belongs to S2
       }

       swap(theArray[first], theArray[lastS1]);
       moveCount = moveCount + 3;
       pivotIndex = lastS1;
    }
    else {// insertion sort part

        int check = 0;

        for (int unsorted = (first + 1); unsorted < last+1; ++unsorted) {
            check = 0;

            int nextItem = theArray[unsorted];
            moveCount++;
            int loc = unsorted;


            compCount++;
            for (  ;(loc > first) && (theArray[loc-1] > nextItem); --loc){

                    check = -1;

                    compCount++;

                moveCount++;

                theArray[loc] = theArray[loc-1];
            }

            if (check == -1)
                compCount--;

            theArray[loc] = nextItem;
            moveCount++;
        }
    }
}

void hybridQuick(int* arr, int first, int last, int& compCount, int& moveCount){

	int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      hybridPartition(arr, first, last, pivotIndex, compCount, moveCount);

      if (last - first <= 10)
        return;

      // sort regions S1 and S2
      hybridQuick(arr, first, pivotIndex-1,compCount, moveCount);
      hybridQuick(arr, pivotIndex+1, last, compCount, moveCount);
   }
}

void hybridSort(int *arr, int size, int &compCount, int &moveCount){
    hybridQuick(arr, 0, size-1, compCount, moveCount);
}

void insertionSort(int *arr, int size, int &compCount, int &moveCount){

    int check = 0;
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        check = 0;

        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;


        compCount++;
        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc){

                check = -1;

                compCount++;

            moveCount++;

            arr[loc] = arr[loc-1];
        }

        if (check == -1)
            compCount--;

        arr[loc] = nextItem;
        moveCount++;
    }

}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int N){
    if (N <= 0){
        arr1 = arr2 = arr3 = NULL;
        return;
    }
    arr1 = new int [N];
    arr2 = new int [N];
    arr3 = new int [N];

    srand( time(NULL) );
    for (int i = 0; i < N; i ++){
        arr1[i] = rand() % (2 * N);
        arr2[i] = arr3[i] = arr1[i];
    }
}

void performanceAnalysis(){

    int* arr, *arr2, *arr3;

    int arrSave [10][4];
    int arrSave2[10][4];
    int arrSave3[10][4];


    int index = 0;
    for (int size = 2000; size < 21000; size += 2000){

        createRandomArrays(arr, arr2, arr3, size);


        double time;


        int compCount = 0;
        int moveCount = 0;


        clock_t begin;
        begin = clock();
        quickSort(arr, 0, size - 1, compCount, moveCount);
        time = clock() - begin;

        arrSave[index][0] = size;
        arrSave[index][1] = time;
        arrSave[index][2] = compCount;
        arrSave[index][3] = moveCount;

        compCount = 0;
        moveCount = 0;


        clock_t begin2;
        begin2 = clock();
        insertionSort(arr2, size, compCount, moveCount);
        time = clock() - begin2;

        arrSave2[index][0] = size;
        arrSave2[index][1] = time;
        arrSave2[index][2] = compCount;
        arrSave2[index][3] = moveCount;

        compCount = 0;
        moveCount = 0;


        clock_t begin3;
        begin3 = clock();

        hybridSort(arr3, size, compCount, moveCount);

        time = clock() - begin3;

        arrSave3[index][0] = size;
        arrSave3[index][1] = time;
        arrSave3[index][2] = compCount;
        arrSave3[index][3] = moveCount;


        index++;
    }

    cout << endl << "------------------------------------------------------------\n"<< endl;
    cout<< "Part a - Time analysis of Quick Sort " << endl;
    cout << "Array size\t" << "Time Elapsed\t" << "compCount\t" << "moveCount" << endl;

    for (int i = 0; i < 10; i++){
            cout << endl;
        for (int j = 0; j < 4; j++)
            cout << arrSave[i][j] << "         \t";

    }


    cout << endl << "------------------------------------------------------------\n"<< endl;
    cout<< "Part b - Time analysis of Insertion Sort " << endl;
    cout << "Array size\t" << "Time Elapsed\t" << "compCount\t" << "moveCount" << endl;

    for (int i = 0; i < 10; i++){
            cout << endl;
        for (int j = 0; j < 4; j++)
            cout << arrSave2[i][j] << "       \t";

    }

    cout << endl << "------------------------------------------------------------\n"<< endl;
    cout<< "Part c - Time analysis of Hybrid Sort " << endl;
    cout << "Array size\t" << "Time Elapsed\t" << "compCount\t" << "moveCount" << endl;

    for (int i = 0; i < 10; i++){
         cout << endl;
        for (int j = 0; j < 4; j++)
            cout << arrSave3[i][j] << "       \t" ;

    }




}
