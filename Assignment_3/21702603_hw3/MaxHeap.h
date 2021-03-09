const int MAX_HEAP2 = 2000;
class MaxHeap {
public:
    MaxHeap();
    void insert(int val);
    int getMax();
    int removeMax();
    int getSize();
    int getHeight();
    int* getGreaterThan(int val);

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:

	int items[MAX_HEAP2];	// array of heap items
	int          size;            	// number of heap items
    void preorderTraversal(int*& array, int nodePtr, int& currentSize, const int limit);


};

