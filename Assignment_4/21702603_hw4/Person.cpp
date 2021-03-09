#include "Person.h"
Person::Person() {
    listOfFriends = nullptr;
}
void Person::addFriend(const Person& person) {


    //if (person.listOfFriends)




    Node* newNode = new Node;
    newNode->p = person;


    if (!person.friendCount){

        newNode->nextPerson = nullptr;

        listOfFriends = newNode;
        friendCount++;

    } else {

        Node* temp = new Node;
        temp = listOfFriends;

        listOfFriends = newNode;
        listOfFriends->nextPerson = temp;
        friendCount++;
    }

}

