#include "MaxHeap.h"
#include <exception>
#include <iostream>
#include <math.h>
using namespace std;

MaxHeap::MaxHeap() : size(0) {

}

void MaxHeap::insert(int val) {
    if (size >= MAX_HEAP2)
		cout << "HeapException: Heap full" << endl;

	// Place the new item at the end of the heap
	items[size] = val;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place] > items[parent]) ) {
		double temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}

int MaxHeap::getMax() {
    if (size)
        return items[0];
    else {
        cout << "HeapException: Heap is empty" << endl;
        return -1;
    }
}

int MaxHeap::removeMax() {
    if (!size)
		cout<<"HeapException: Heap is empty"<<endl;
	else {
		int temp = items[0];
		items[0] = items[--size];
		heapRebuild(0);

		return temp;
	}
    return -1;
}

int MaxHeap::getSize() {return size;}

int MaxHeap::getHeight() {
    if (size)
        return log2(size) + 1 ;
    else
        return 0;
}

void MaxHeap::heapRebuild(int root) {
    int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild] > items[child]) )
			child = rightChild; 	// index of larger child

		// If root's item is larger than larger child, swap values
		if ( items[root] < items[child] ) {
			double temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}

int* MaxHeap::getGreaterThan(int val) {

    int* array = new int[size]; // probably array will not be full.

    int nodePtr = 0;
    int currentSize = 0;
    preorderTraversal(array, nodePtr, currentSize, val);

    int* returnThisArray = new int [currentSize]; // copying the items since a part of this array has garbage value.

    for (int i = 0; i < currentSize; i++) {
        returnThisArray[i] = array[i];
    }

    return returnThisArray;
}

void MaxHeap::preorderTraversal(int*& array, int nodePtr, int& currentSize, const int limit) {

    if (nodePtr >= size )
        return;

    if ( items[nodePtr] > limit ) { // this is where we add an item to the list.
        array [currentSize] = items[nodePtr];
        currentSize++;

    }

    preorderTraversal(array, (nodePtr*2 + 1), currentSize, limit); // go left child
    preorderTraversal(array, (nodePtr*2 + 2), currentSize, limit); // go right child
}




