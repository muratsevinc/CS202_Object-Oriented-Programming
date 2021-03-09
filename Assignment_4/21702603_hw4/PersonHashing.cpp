#include "PersonHashing.h"
using namespace std;

PersonHashing::PersonHashing() {
    for (int i = 0; i < 11; i++)
        hashTable[i] = nullptr;
}

int PersonHashing::hash(const string &key, int tableSize) {

	int hashVal = 0;

	for (int i = 0; i < key.length(); i++) {
        if (key[i] != 13){

            hashVal += key[i];
        }
	}
	return hashVal % tableSize;
}

void PersonHashing::insertToHash(const Person newPerson) {
    int index = hash(newPerson.name, 11); // find where to insert
    index = hash(newPerson.name, 11);
    Node* linkedListHead = hashTable[index]; // fetch the linked list.

    // now insert at the end of the linked list.
    if (linkedListHead == nullptr) { // if part: corner case: if linked list is empty.

        linkedListHead = new Node();

        linkedListHead->p = newPerson;
        linkedListHead->nextPerson = nullptr;

        hashTable[index] = linkedListHead;

    }
    else {                          // else part: go until cur->next is null. Then insert
        while (linkedListHead->nextPerson != nullptr)
            linkedListHead = linkedListHead->nextPerson;

        Node* newPersonNode = new Node(); // creating new Person Node.
        newPersonNode->p = newPerson;
        newPersonNode->nextPerson = nullptr;

        linkedListHead->nextPerson = newPersonNode; // provide the connection.
    }
}

Person PersonHashing::findPerson(const string& key, int tableSize) {
    int index = hash(key, 11);

    Node* linkedList = hashTable[index];

    if (linkedList == nullptr) {
        cout << "not found." << endl;

    }


    while (linkedList->nextPerson != nullptr && linkedList->p.name != key )
        linkedList = linkedList->nextPerson;

    if (linkedList->p.name == key) {
        return linkedList->p;
    }
}
