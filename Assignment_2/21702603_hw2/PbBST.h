/**
* Title : Binary Search Trees
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 2
* Description : Header file of BST
*/

#include "PbBSTNode.h"
class PbBST{

public:
    PbBST();
    double medianOfBST();
    void insertKey(int key);
    void deleteKey(int key);
    void preorderTraversal();
    int getHeight();
    int getNodeCount();
    int findNodesRequired();
    void mirrorTree();
private:
    PbBSTNode* root;
    void insertItem(PbBSTNode*& root, const int& item);
    void deleteItem(PbBSTNode*& treePtr, int searchKey);
    void deleteNodeItem(PbBSTNode *& nodePtr);
    void processLeftmost(PbBSTNode *&nodePtr, int& treeItem);
    void traverseInorder(PbBSTNode*& treePtr);
    void preorderTraversalRecursively(PbBSTNode*& treePtr);
    void getNodeCountRecursively(PbBSTNode*& treePtr, int& count);
    int getHeightRecursively(PbBSTNode*& treePtr);
    void mirrorTreeRecursively(PbBSTNode*& treePtr);
    void putThemIntoArray(PbBSTNode*& treePtr, int*& items, int& current);
};
