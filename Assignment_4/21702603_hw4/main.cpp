#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Person.h"
#include "Friendship.h"
#include "PersonHashing.h"
#include "FriendshipHashing.h"

using namespace std;


// forward declarations for my helper methods
void fetchCharIndexesOfLine(int lineNo, int& startingCharIndex, int& endingCharIndex);
string getOrder(const int startingCharIndex, const int endingCharIndex);
string constructFriendshipName(string name1, string name2);
void executeTheOrder(const string theOrder);
// end of forward declarations


char* chars = new char; // the txt file itself in char array form


PersonHashing personHashTable;
FriendshipHashing friendshipHashTable;

Friendship fs;
int main() {

    fstream fin( "input.txt" , fstream::in);

    int textSize = 0;
    int totalLineNo = 0;
    char ch;

    while (fin >> noskipws >> ch) {
        chars[textSize] = ch;

        textSize++;

    }

    for (int i = 0; i < textSize; i++) {

        if (chars[i] == '\n')
            totalLineNo++;
    }


    for (int i = 0; i < totalLineNo; i++) {
        int startingCharIndex, endingCharIndex;
        fetchCharIndexesOfLine(i, startingCharIndex, endingCharIndex);
        string order = getOrder(startingCharIndex, endingCharIndex);
        executeTheOrder(order);
    }

    return 0;
}

void fetchCharIndexesOfLine(int lineNo, int& startingCharIndex, int& endingCharIndex) {

    startingCharIndex = 0;

    int currentLine = 0;

    while(currentLine != lineNo) {

        if (chars[startingCharIndex] == '\n')
            currentLine++;

        startingCharIndex++;
    }


    endingCharIndex = startingCharIndex;

    while (chars[endingCharIndex] != '\n')
        endingCharIndex++;


}

string getOrder(const int startingCharIndex, const int endingCharIndex) {
    string theOrder;


    for (int i = startingCharIndex; i < endingCharIndex; i++) {
        theOrder += chars[i];
    }


    return theOrder;
}

void executeTheOrder(const string theOrder) {
    int beginningIndex = 0;
    int endingIndex = theOrder.length();

    char orderType = theOrder[beginningIndex];

    string arg1, arg2;


    while(theOrder[beginningIndex] != ' ' && beginningIndex < endingIndex)
        beginningIndex++;

    beginningIndex++;

    while (theOrder[beginningIndex] != ' ' && beginningIndex < endingIndex) {
        arg1 += theOrder[beginningIndex];
        beginningIndex++;
    }

    beginningIndex++;

    while (theOrder[beginningIndex] != ' ' && beginningIndex < endingIndex) {
        arg2 += theOrder[beginningIndex];
        beginningIndex++;
    }

    //cout << " \tOrder Type: " << orderType << " name1: " << arg1 << " name2: " << arg2 << endl;


    if (orderType == 'P') {
        Person newPerson;
        newPerson.name = arg1;

        personHashTable.insertToHash(newPerson);
        cout << "Person " << arg1 << " successfully created.\n" << endl;
    }
    else if (orderType == 'F') {

        if (arg1 == arg2) {
            cout << "You cannot unfriend yourself." << endl << endl;
            return;
        }

        Person p1 = personHashTable.findPerson(arg1, 11);
        Person p2 = personHashTable.findPerson(arg2, 11);



        fs.friendshipName = constructFriendshipName(p1.name, p2.name);
        friendshipHashTable.insertFriendship(fs);
        cout << "Friendship " << fs.friendshipName << " is successfully created.\n" << endl;
    }
    else if (orderType == 'U') {

        if (arg1 == arg2) {
            cout << "You cannot unfriend yourself." << endl << endl;
            return;
        }


        string friendshipName = constructFriendshipName(arg1, arg2); // friendship name is constructed.

        fs = friendshipHashTable.hashTable[friendshipHashTable.findTheIndex(friendshipName, 71)];
        friendshipHashTable.deleteFriendship(fs);
    }
    else if (orderType == 'L') {
        cout << "L command does not work :( " << endl;

    }
    else if (orderType == 'Q') {
        string friendshipName = constructFriendshipName(arg1, arg2); // friendship name is constructed.

        int index = friendshipHashTable.findTheIndex(friendshipName, 71);

        if (index != -1)
            cout << "Yes " << arg1 << " and " << arg2 << " are friends. " << endl;
        else
            cout << "No "  << arg1 << " and " << arg2 << " are NOT friends. "<< endl;
    }
    else if (orderType == 'X') {
        cout << "Terminating the program.";
        exit(EXIT_SUCCESS);
    }
}

string constructFriendshipName(string name1, string name2) {
        if (name1 < name2)
            return name1 + name2;
        else
            return name2 + name1;
}



















