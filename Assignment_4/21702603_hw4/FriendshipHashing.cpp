#include "Friendship.h"
#include "FriendshipHashing.h"


FriendshipHashing::FriendshipHashing() {
    hashTable = new Friendship[71];
    hashSize = 0;

}

void FriendshipHashing::insertFriendship(const Friendship& fs) {

    int index = hash(fs.friendshipName, 71);

    if (hashSize < 70){
        hashTable[index] = fs;
        cellHistory[index] = false;

        hashSize++;
    }
    else
        cout << "Table is Full! You are trying to insert more than 71 values!" << endl;


}

int FriendshipHashing::hash(const string &key, int tableSize) {
	int hashVal = 0;

	for (int i = 0; i < key.length(); i++) {
        if (key[i] != 13)
            hashVal += key[i];

	}

	for (int tryNo = 0; hashTable[hashVal% tableSize].friendshipName != ""; tryNo++ ) { // quadratic probing part:

        hashVal += (2 * tryNo) + 1 ;

	}
	return hashVal % tableSize;
}

void FriendshipHashing::deleteFriendship(const Friendship& fs) {
    int index = findTheIndex(fs.friendshipName, 71);
    if (index == -1) {
        cout << "Friendship could not found: 404" << endl;
        return;
    }
    else {
        Friendship nullFriendship;
        hashTable[index] = nullFriendship;
        cellHistory[index] = true;
        hashSize--;
    }


}

int FriendshipHashing::findTheIndex(const string &key, int tableSize) {

    int hashVal = 0;

	for (int i = 0; i < key.length(); i++) {

        if (key[i] != 13) // block space
            hashVal += key[i] %71;
	}
	hashVal = hashVal % 71;

	for (int tryNo = 0; hashTable[hashVal % tableSize].friendshipName != key; tryNo++ ) { // quadratic probing part:

        Friendship friendship = hashTable[hashVal %tableSize];
        if (friendship.friendshipName.length() == 0 )
            if (!cellHistory[hashVal % tableSize])// cell is empty and has never been used before.
                return -1;

        hashVal += (2 * tryNo) + 1 ;
        hashVal = hashVal % 71;
	}

	return hashVal % 71;

}

