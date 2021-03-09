#include <iostream>
#include "QuickMedian.h"
using namespace std;

int main () {

// part 1 -- Min Heap:
    MinHeap minHeap;

    minHeap.insert(15);
    minHeap.insert(50);
    minHeap.insert(45);
    minHeap.insert(30);
    minHeap.insert(60);
    minHeap.insert(55);
    minHeap.insert(20);
    minHeap.insert(35);
    minHeap.insert(10);
    minHeap.insert(25);
    minHeap.insert(65);

    cout << "Minimum value of min-heap: " << minHeap.getMin() << endl << endl;
    cout << "Size of min-heap: " << minHeap.getSize() << endl << endl;
    cout << "Height of min-heap: " << minHeap.getHeight() << endl << endl;

    int* minValues = minHeap.getLessThan(40);
    cout << "Values that are less than 40: " << endl;
    for (int i = 0; i < 6; i++) // i < 6 is manually added, this is only to block printing garbage values, since array size is unknown.
        cout << minValues[i] << " ";

    cout << "\n\n---------\n\n";
// end of part 1
// part 2 -- Max Heap:

    MaxHeap maxHeap;

    maxHeap.insert(15);
    maxHeap.insert(50);
    maxHeap.insert(45);
    maxHeap.insert(30);
    maxHeap.insert(60);
    maxHeap.insert(55);
    maxHeap.insert(20);
    maxHeap.insert(35);
    maxHeap.insert(10);
    maxHeap.insert(25);
    maxHeap.insert(65);

    cout << "Maximum value of max-heap: " << maxHeap.getMax() << endl << endl;
    cout << "Size of max-heap: " << maxHeap.getSize() << endl << endl;
    cout << "Height of max-heap: " << maxHeap.getHeight() << endl << endl;

    int* maxValues = maxHeap.getGreaterThan(40);
    cout << "Values that are greater than 40: " << endl;
    for (int i = 0; i < 5; i++) // i < 6 is manually added, this is only to block printing garbage values, since array size is unknown.
        cout << maxValues[i] << " ";

    cout << "\n\n---------\n\n";

// end of part 2
// part 3 -- Quick Median:

    QuickMedian quickMedian;

    quickMedian.insert(10);
    quickMedian.insert(40);
    quickMedian.insert(30);
    quickMedian.insert(50);
    quickMedian.insert(70);
    quickMedian.insert(60);
    quickMedian.insert(20);
    quickMedian.insert(90);
    quickMedian.insert(100);
    quickMedian.insert(110);
    quickMedian.insert(0);
    quickMedian.insert(25);
    quickMedian.insert(123);
    quickMedian.insert(11);
    quickMedian.insert(200);

    cout << "Median of Quick Median: " << quickMedian.getMedian() << endl;
// end of part 3

    return 0;
}
