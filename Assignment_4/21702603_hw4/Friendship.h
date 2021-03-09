#ifndef Friendship_h
#define Friendship_h

#include <iostream>
#include "Person.h"
using namespace std;
class Friendship {
public:
    Friendship();
    Friendship(const Person a, const Person b);
    string friendshipName;

    Node* pointerToFriend1InFriend2sList;
    Node* pointerToFriend2InFriend1sList;
};
#endif
