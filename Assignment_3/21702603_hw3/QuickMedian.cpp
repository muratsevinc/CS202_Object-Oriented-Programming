#include "QuickMedian.h"
#include <iostream>
using namespace std;

QuickMedian::QuickMedian() {
    size = 0;
}

void QuickMedian::insert(int val) {

    if (size > 0 && getMedian() > val)
        maxHeap.insert(val);
    else
        minHeap.insert(val);

    if (minHeap.getSize() > maxHeap.getSize() + 1) {
        minToMax();
    }

    if (maxHeap.getSize() > minHeap.getSize() + 1){
        maxToMin();
    }

    size++;

}

double QuickMedian::getMedian() {

    if ( minHeap.getSize() > maxHeap.getSize())
        return minHeap.getMin();
    else if (minHeap.getSize() == maxHeap.getSize())
        return ((double)(maxHeap.getMax() + minHeap.getMin()) / 2);
    else {
        return maxHeap.getMax();
    }
}

void QuickMedian::minToMax() {
    maxHeap.insert(minHeap.removeMin());
}

void QuickMedian::maxToMin() {
    minHeap.insert(maxHeap.removeMax());
}







