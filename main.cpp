/*********************
Name: Logan Falkenberg
Test 2
Purpose: This is the test file for my hash table class. It tests all possible cases, hundreds of times.
**********************/
#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }

    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    srand(time(NULL));

    bool didInsert = false;
    bool didRemove = false;
    std::string data;
    int rNumCase = 0;
    int rNumIndex = 0;
    int id = 0;
    int iterationCount = 1;

    // create your hash table object here
    Hashtable table;

    // show it is empty by calling getCount and printTable
    std::cout << "\nCurrent amount of entries: " << table.getCount() << std::endl;
    std::cout << "printing table: " << std::endl;
    table.displayTable();
    std::cout << std::endl;

    // try and put ALL the test data into the table and show what happens
    // Testing insert/remove methods
    std::cout << "\n**TESTING INSERT/REMOVE**" << std::endl;
    for(int i =0; i < testdatasize; i++){
        didInsert = table.addEntry(ids[i], &strs[i]);
        int location = ids[i] % HASHTABLESIZE;
        std::cout << "insert of id " << ids[i] << " at table entry " << location << " successful? ";
        if(didInsert == true){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    std::cout << "\nCurrent amount of entries: " << table.getCount() << std::endl;
    std::cout << "printing table: " << std::endl;
    table.displayTable();
    std::cout << std::endl;

    std::string dataString = "";

    for(int i =0; i < testdatasize; i++){
        didRemove = table.removeEntry(ids[i]);
        int location = ids[i] % HASHTABLESIZE;
        dataString = table.getEntry(ids[i]);
        std::cout << "Retrieving entry of id " << ids[i] << " before removal. Entry: " << dataString << std::endl;
        std::cout << "removal of id " << ids[i] << " at table entry " << location << " successful? ";
        if(didRemove == true){
            std::cout << "yes\n" << std::endl;
        } else {
            std::cout << "no\n" << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "\nCurrent amount of entries: " << table.getCount() << std::endl;
    std::cout << "printing table: " << std::endl;
    table.displayTable();
    std::cout << std::endl;

    // Main testing for loop
    std::cout << "\n**TESTING ALL METHODS**" << std::endl;
    for(int i =0; i < 1000; i++){
        // Picks random index
        rNumIndex = (rand() % testdatasize);
        rNumCase = (rand()%3)+1;
        int location = 0;
        std::cout<<"\nIteration: " << iterationCount << std::endl;

        switch(rNumCase){
            case 1:
                location = ids[rNumIndex] % HASHTABLESIZE;
                std::cout << "insert of id " << ids[rNumIndex]<< " at table entry " << location << " successful? ";
                didInsert = table.addEntry(ids[rNumIndex], &strs[rNumIndex]);
                if(didInsert == true){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "Current amount of entries: " << table.getCount() << std::endl;
                std::cout << "printing table: " << std::endl;
                table.displayTable();
                std::cout << std::endl;
                break;

            case 2:
                didRemove = table.removeEntry(ids[rNumIndex]);
                location = ids[rNumIndex] % HASHTABLESIZE;
                std::cout << "removal of id " << ids[rNumIndex] << " at table entry " << location << " successful? ";
                if(didRemove == true){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "Current amount of entries: " << table.getCount() << std::endl;
                std::cout << "printing table: " << std::endl;
                table.displayTable();
                std::cout << std::endl;
                break;

            case 3:
                id = ids[rNumIndex];
                data = table.getEntry(id);
                std::cout << "data from id: " << id << ": " << data << std::endl;
                break;
        }
        iterationCount++;
    }

    std::cout << "\n***************\nTESTS CONCLUDED\n***************" << std::endl;

    return 0;
}