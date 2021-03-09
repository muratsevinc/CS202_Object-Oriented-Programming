/**
* Title : Binary Search Trees
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 2
* Description : Implementation of BST Node.
*/

#include "PbBSTNode.h"

PbBSTNode::PbBSTNode() {

}

PbBSTNode::PbBSTNode(const int& nodeItem, PbBSTNode *left, PbBSTNode *right) {
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}
