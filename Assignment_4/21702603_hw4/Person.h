#ifndef Person_h
#define Person_h
#include <iostream>

using namespace std;

class Node;

class Person {
public:
    Person();
    string name;
    void addFriend(const Person& person);
    Node* listOfFriends;
    int friendCount;
};

class Node {
public:
    Node* nextPerson;
    Person p;
    Node& operator=(const Node& other) {
      nextPerson = other.nextPerson;
      p = other.p;
      return *this;
    }
};

#endif
