/**
* Title : Binary Search Trees
* Author : Murat Sevinç
* ID: 21702603
* Section : 1
* Assignment : 2
* Description : Main.cpp file that creates a BST and analyzes the tree
*
*/

#include <iostream>
#include "PbBST.h"
#include "analysis.h"
using namespace std;

int main() {

    PbBST tree;

    tree.insertKey(42);
    tree.insertKey(19);
    tree.insertKey(22);
    tree.insertKey(35);
    tree.insertKey(56);
    tree.insertKey(11);
    tree.insertKey(94);
    tree.insertKey(32);
    tree.insertKey(28);
    tree.insertKey(8);
    tree.insertKey(6);
    tree.insertKey(81);
    tree.insertKey(63);
    tree.insertKey(13);
    tree.insertKey(45);


    cout << "Nodes are inserted." << endl;
    cout << "Tree has " << tree.getNodeCount() << " nodes now." << endl;
    cout << "Height of the tree is: " << tree.getHeight() << " now." << endl;
    cout << "Needed nodes to be a full tree: " << tree.findNodesRequired() << endl;
    cout << "\nMedian of the tree(before deleting 19 and 56): " << tree.medianOfBST();
    tree.preorderTraversal();

    tree.deleteKey(56);
    tree.deleteKey(19);
    cout << "\n\nNodes 56 and 19 are deleted." << endl;
    cout << "Tree has " << tree.getNodeCount() << " nodes now." << endl;
    cout << "Height of the tree is: " << tree.getHeight() << " now." << endl;
    cout << "Needed nodes to be a full tree: " << tree.findNodesRequired() << endl;
    cout << "\nMedian of the tree: " << tree.medianOfBST();

    tree.mirrorTree();
    cout << "\nTree is now mirrored.\n";
    tree.preorderTraversal();

    heightAnalysis();

    return 0;
}











