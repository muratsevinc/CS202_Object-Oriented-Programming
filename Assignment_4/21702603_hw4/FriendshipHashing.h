#include "Friendship.h"

class FriendshipHashing {
public:
    FriendshipHashing();
    Friendship* hashTable;
    void insertFriendship(const Friendship& fs);
    void deleteFriendship(const Friendship& fs);
    bool cellHistory[71]; // in case of deletions, this will provide the history, if used before, go on searching.
    int findTheIndex(const string &key, int tableSize);

private:
    int hash(const string& key, int tableSize);
    int hashSize;

};
