#include "Person.h"

class PersonHashing {
public:
    PersonHashing();
    Node* hashTable[11]; // note that Node is a LinkedList node which has Person object and pointer to the next node.
    void insertToHash(const Person newPerson);
    Person findPerson(const string& key, int tableSize);
private:
    int hash(const string& key, int tableSize);
};
