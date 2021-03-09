/**
* Title : Binary Search Trees
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 2
* Description : Header file of BST Node.
*/

#include <cstddef>
class PbBSTNode {            // node in the tree
private:
    PbBSTNode();
    PbBSTNode(const int& nodeItem,
        PbBSTNode *left = NULL,
        PbBSTNode *right = NULL);
//        :item(nodeItem),leftChildPtr(left),rightChildPtr(right) {};

    int item;       // data portion
    PbBSTNode *leftChildPtr;  // pointer to left child
    PbBSTNode *rightChildPtr; // pointer to right child

    friend class PbBST;

private:


};
