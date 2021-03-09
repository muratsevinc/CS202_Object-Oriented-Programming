#include "analysis.h"
#include <iostream>
#include "PbBST.h"
using namespace std;
void heightAnalysis() {
    const string line = "---------------------------------------------------------\n";
    const string header = "Tree Size\tTree Height\n";

    cout << "\n\nPart e - Height analysis of Binary Search Tree - part 1" << endl;
    cout << line << header << line;




    int array[15000];
    PbBST tree;
    for (int i = 0; i < 15000; i++){
        array[i] = rand();
        tree.insertKey(array[i]);

        if (((i+1) % 1500) == 0)
            cout << tree.getNodeCount() << "\t\t" << tree.getHeight() << endl;
    }


    cout << "\n\nPart e - Height analysis of Binary Search tree - part 2" << endl;
    cout << line << header << line;

    // shuffling the array:

    for (int el = 0; el < 15000; el++) {
        int itemIndex1 = rand() % 15000;
        int itemIndex2 = rand() % 15000;

        // swap below
        int save = array[itemIndex1];
        array[itemIndex1] = array[itemIndex2];
        array[itemIndex2] = save;
    }
    // end of shuffling.


    for (int iteration = 14999; iteration >= 0; iteration--) {

        tree.deleteKey(array[iteration]);

        if ((iteration % 1500) == 0)
            cout << tree.getNodeCount() << "\t\t" << tree.getHeight() << endl;

    }






}
