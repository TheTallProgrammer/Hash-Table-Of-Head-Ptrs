/*********************
Name: Logan Falkenberg
Test 2
Purpose: The header file for the hashtable class. Contains all prototypes and attributes for the class.
**********************/

#ifndef HASHTABLE_TEST_HASH_H
#define HASHTABLE_TEST_HASH_H
#define HASHTABLESIZE 10
#include <iostream>
#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
};

class Hashtable{

public:
    Hashtable();
    ~Hashtable();
    bool addEntry(int, string *);
    string getEntry(int);
    bool removeEntry(int);
    int getCount();
    void displayTable();

private:

    int hash(int);
    bool addNode(int, int, std::string *);
    void initializeNode(int *, string*, Node*);
    int count;
    Node *hashtable[HASHTABLESIZE];

};
#endif //HASHTABLE_TEST_HASH_H
