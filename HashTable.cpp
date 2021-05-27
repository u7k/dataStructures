// Uygur Kiran - 2021/05/27
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// {{int: str}}
class HashTable {
private:
    static const int count = 10; // of each {key:value} pair
    list<pair<int, string>> table[count];
public:
    bool isEmpty();
    int hashFunc(int key);
    void insert(int key, string val);
    void remove(int key);
    string find(int key);
    void print();
};

bool HashTable::isEmpty() {
    int sum{};
    for(int i{}; i < count; i++) {
        sum += table[i].size();
    }
    return (!sum);
}

int HashTable::hashFunc(int key) {
    return key % count;
}

void HashTable::insert(int key, string val) {
    int hashVal = hashFunc(key);
    auto& pair = table[hashVal];
    auto bItr = begin(pair);

    bool keyExists = false;
    for (; bItr != end(pair); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = val;
            cout << "WARNING: existing key found. replacing the value." << endl;
            break;
        }
    } //: LOOP

    if(!keyExists) {
        pair.emplace_back(key, val);
    }
}

void HashTable::remove(int key) {
    int hashVal = hashFunc(key);
    auto& pair = table[hashVal];
    auto bItr = begin(pair);

    bool keyExists = false;
    for (; bItr != end(pair); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = pair.erase(bItr);
            break;
        }
    } //: LOOP

    if(!keyExists) {
       cout << "ERROR: item not found" << endl;
    }
}

void HashTable::print() {
    cout << endl << "{";
    for(int i{}; i < count; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "\n\t" << bItr->first << ": " << bItr->second;
        }
    }
    cout << endl << "}" << endl;
}

int main() {
    HashTable dict;
    dict.insert(8, "ismet");
    dict.insert(16, "qwerty");
    dict.insert(24, "yioy");
    dict.insert(32, "remove");
    dict.insert(64, "fghjhjg");
    dict.insert(128, "zxcvxczv");
    dict.insert(256, "cvbcvnb");

    dict.print();
    dict.remove(32);
    dict.insert(8, "ISMET");
    dict.print();

    return 0;
}