#include "Friendship.h"

Friendship::Friendship(const Person p1, const Person p2) {
    cout << "friendship in" << endl;
    if (p1.name < p2.name)
        friendshipName = p1.name + p2.name;
    else
        friendshipName = p2.name + p1.name;
/*
    Node* cur = p1.listOfFriends;

    if (cur != nullptr) {
        while (cur->p.name != p2.name && cur->nextPerson != nullptr)
            cur = cur->nextPerson;

        pointerToFriend2InFriend1sList = cur;

        cur = p2.listOfFriends;
        while (cur->p.name != p1.name && cur->nextPerson != nullptr)
            cur = cur->nextPerson;

        pointerToFriend1InFriend2sList = cur;
    }
*/

}

Friendship::Friendship() {

}
