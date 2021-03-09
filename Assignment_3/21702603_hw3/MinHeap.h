const int MAX_HEAP = 2000;
class MinHeap {
public:
    MinHeap();
    void insert(int val);
    int getMin();
    int removeMin();
    int getSize();
    int getHeight();
    int* getLessThan(int val);

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:

	int items[MAX_HEAP];	// array of heap items
	int          size;            	// number of heap items
    void preorderTraversal(int*& array, int nodePtr, int& currentSize, const int limit);


};

