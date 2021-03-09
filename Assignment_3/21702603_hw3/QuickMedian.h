#include "MinHeap.h"
#include "MaxHeap.h"
using namespace std;
class QuickMedian {
public:
    QuickMedian();
    void insert(int val); // inserts an element into QuickMedian
    double getMedian(); // returns the median of elements
private:
    MinHeap minHeap;
    MaxHeap maxHeap;

    int size;

    void minToMax();
    void maxToMin();
};
