/**
* Title : Binary Search Trees
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 2
* Description : Implementation of BST.
*/

#include "PbBST.h"
#include <iostream>
#include <math.h>
using namespace std;
PbBST::PbBST(){
    root = NULL;

}

void PbBST::insertKey(int key){
    insertItem(root, key);
}

void PbBST::deleteKey(int key){
    deleteItem(root, key);
}

void PbBST::insertItem(PbBSTNode *& treePtr, const int& newItem) {
		if (treePtr == NULL) {
			treePtr = new PbBSTNode(newItem);
		}

		else if (newItem < treePtr->item)
			insertItem(treePtr->leftChildPtr, newItem);
		else
			insertItem(treePtr->rightChildPtr, newItem);
}

void PbBST::deleteItem(PbBSTNode*& treePtr, int searchKey) {
		if (treePtr == NULL) // Empty tree
			return;

		// Position of deletion found
		else if (searchKey == treePtr->item)
			deleteNodeItem(treePtr);

		// Else search for the deletion position
		else if (searchKey < treePtr->item)
			deleteItem(treePtr->leftChildPtr, searchKey);
		else
			deleteItem(treePtr->rightChildPtr, searchKey);
}

void PbBST::deleteNodeItem(PbBSTNode *& nodePtr){
    PbBSTNode *delPtr;
    int replacementItem;

    if ( (nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL) ) {
			delete nodePtr;
			nodePtr = NULL;
    }

    else if (nodePtr->leftChildPtr == NULL){
			delPtr = nodePtr;
			nodePtr = nodePtr->rightChildPtr;
			delPtr->rightChildPtr = NULL;
			delete delPtr;
    }

    else if (nodePtr->rightChildPtr == NULL) {
			delPtr = nodePtr;
			nodePtr = nodePtr->leftChildPtr;
			delPtr->leftChildPtr = NULL;
			delete delPtr;
		}
    else {
			processLeftmost(nodePtr->rightChildPtr, replacementItem);
			nodePtr->item = replacementItem;
    }
}

void PbBST::processLeftmost(PbBSTNode *&nodePtr, int& treeItem){

		if (nodePtr->leftChildPtr == NULL) {
			treeItem = nodePtr->item;
			PbBSTNode *delPtr = nodePtr;
			nodePtr = nodePtr->rightChildPtr;
			delPtr->rightChildPtr = NULL; // defense
			delete delPtr;
		}
		else
			processLeftmost(nodePtr->leftChildPtr, treeItem);
}




void PbBST::preorderTraversal(){
    cout << "\n\nPreorder Traversal of tree: \n";
    preorderTraversalRecursively(root);

}


void PbBST::preorderTraversalRecursively(PbBSTNode*& treePtr){
    if (treePtr != NULL) {
            cout << treePtr->item << endl;
			preorderTraversalRecursively(treePtr->leftChildPtr);
			preorderTraversalRecursively(treePtr->rightChildPtr);
    }
}

int PbBST::getHeight(){
    return getHeightRecursively(root);
}

int PbBST::getHeightRecursively(PbBSTNode*& treePtr){
    if(treePtr == NULL)
        return 0;

    int maxValue = max(getHeightRecursively(treePtr->leftChildPtr), getHeightRecursively(treePtr->rightChildPtr));

    return 1 + maxValue;
}


void PbBST::getNodeCountRecursively(PbBSTNode*& treePtr, int& count) {
    if (treePtr != NULL) {
			getNodeCountRecursively(treePtr->leftChildPtr, count);
			count++;
			getNodeCountRecursively(treePtr->rightChildPtr, count);
    }

}

int PbBST::getNodeCount(){
    int count = 0;
    getNodeCountRecursively(root, count);
    return count;

}

int PbBST::findNodesRequired(){
    return pow(2, getHeight()) - getNodeCount() - 1;
}

void PbBST::mirrorTree(){
    mirrorTreeRecursively(root);
}

void PbBST::mirrorTreeRecursively(PbBSTNode*& treePtr){
    if (treePtr->leftChildPtr == NULL && treePtr->rightChildPtr == NULL)
        return;

    PbBSTNode* saveNode = treePtr->rightChildPtr;
    treePtr->rightChildPtr = treePtr->leftChildPtr;
    treePtr->leftChildPtr = saveNode;


    if (treePtr->leftChildPtr != NULL)
        mirrorTreeRecursively(treePtr->leftChildPtr);

    if (treePtr->rightChildPtr != NULL)
        mirrorTreeRecursively(treePtr->rightChildPtr);
}

double PbBST::medianOfBST(){

    int current = 0;
    int size = getNodeCount(); // O(n) time.

    int* items = new int[size];

    putThemIntoArray(root, items, current); //  Also O(n) time.

    if (size % 2 == 1){
        return items[size/2];
    }
    else {
        return (double)(items[(size/2)] + items[size/2 - 1]) / 2;
    }

}

void PbBST::putThemIntoArray(PbBSTNode*& treePtr, int*& items, int& current) {
    if (treePtr != NULL) {
			putThemIntoArray(treePtr->leftChildPtr, items, current);

			items[current] = treePtr->item;
			current++;

			putThemIntoArray(treePtr->rightChildPtr, items, current);
    }
}











