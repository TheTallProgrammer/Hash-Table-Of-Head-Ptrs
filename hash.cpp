/*********************
Name: Logan Falkenberg
Test 2
Purpose: This is the main file for hashtable class. Contains all fully functional methods
**********************/
#include "hash.h"

Hashtable::Hashtable() {
    count = 0;
    for(int i = 0; i < HASHTABLESIZE; i++){
        hashtable[i] = nullptr;
    }
} // End of constructor

Hashtable::~Hashtable(){
    count = 0;
    for(int i = 0; i < HASHTABLESIZE; i++){
        delete hashtable[i];
    }
} // End of destructor

bool Hashtable::addEntry(int id, string *data) {
    bool didInsert = false;
    int location = hash(id);
    if(id >= 0 && data->length() > 0 && count != HASHTABLESIZE) {
        didInsert = addNode(location, id, data);
    }
    return didInsert;
} // End of addEntry

bool Hashtable::addNode(int location, int id, std::string *data) {
    bool didAdd = false;
    Node *head = hashtable[location];
    Node *position = head;
    if (id >= 0 && data->length() > 0) {
        while ((head != nullptr) && position->data.id != id && position->next != nullptr) {// Loops through the list to find a spot for the node
            position = position->next;
        }
        if (head != nullptr && id == position->data.id) {}
        else if (head == nullptr) {// First head node
            Node *newNode = new Node();
            initializeNode(&id, data, newNode);
            hashtable[location] = newNode;
            std::cout << hashtable[location]->data.id << std::endl;
            didAdd = true;
            count++;
        } else if (position->next == nullptr) {
            Node *newNode = new Node();
            initializeNode(&id, data, newNode);
            position->next = newNode;
            position->next->next = nullptr;
            didAdd = true;
            count++;
        }
    }
    return didAdd;
} // End of addNode

std::string Hashtable::getEntry(int id){
    std::string data = "";
    bool result = false;
    for(int i =0; i < HASHTABLESIZE; i++){
        Node *position = hashtable[i];
        while (position != nullptr && !result) {
            if(id == position->data.id){
                data = position->data.data;
                result = true;
            } else{
                position = position->next;
            }
        }
    }
    return data;
} // End of getEntry

bool Hashtable::removeEntry(int id){
    bool didRemove = false;
    int location = hash(id);
    bool result = false;
    if(id >= 0) {
        std::cout << "attemping to remove id " << id << std::endl;
        Node *head = hashtable[location];
        Node *position = head;
        while (position != nullptr && !result) {
            if (id == position->data.id) {
                if (position == head) {
                    std::cout << "head" << std::endl;
                    position = position->next;
                    hashtable[location] = position;
                    delete head;
                    didRemove = true;
                    result = true;
                    count--;
                } else if (position->next){
                    std::cout << "middle" << std::endl;
                    Node *curr, *prev;
                    curr = head;
                    while(curr != position){
                        prev = curr;
                        curr = curr->next;
                    }
                    prev->next = curr->next;
                    delete position;
                    didRemove = true;
                    result = true;
                    count--;
                } else if (position->next == nullptr){
                    std::cout << "tail" << std::endl;
                    Node*prev= nullptr;
                    Node*curr= head;
                    while(curr!=position){
                        prev= curr;
                        curr=curr->next;
                    }
                    prev->next= nullptr;
                    delete position;
                    didRemove = true;
                    result = true;
                    count--;
                }
            }
            if(!result)
                position = position->next;
        }
    }
        return didRemove;
} // End of removeEntry

int Hashtable::getCount(){return count;} // End of getCount

void Hashtable::displayTable(){
    int loopCount = 1;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        Node *head = hashtable[i];
        Node *position = head;
        std::cout << "\tTable Entry: " << i << " : ";
        while (position != nullptr) {
            std::cout << position->data.id;
            if(position->next != nullptr){
                std::cout << " --> ";
            }
            position = position->next;
            loopCount += 1;
        }
        std::cout << "" << std::endl;
    }
} // End of displayTable

// Private methods
int Hashtable::hash(int id) {return id % HASHTABLESIZE;} // End of hash

void Hashtable::initializeNode(int *id, string *data, Node *newNode){
    newNode->data.id = *id;
    newNode->data.data = *data;
    newNode->next = nullptr;
} // End of initializeNode