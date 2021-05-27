// Uygur Kiran - 2021/05/17

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* newNode(int item) {
        Node* newN = new Node();
        newN -> data = item;
        newN -> prev = NULL;
        newN -> next = NULL;
        return newN;
    }
public:
    Node* headNode = NULL;

    void insertAtHead(int item) {
        Node* temp = newNode(item); // temp pointer
        if (headNode == NULL) { headNode = temp; return; }

        headNode -> prev = temp;
        temp -> next = headNode;
        headNode = temp; // point inserted item
    }

    void print() {
        Node* temp = headNode;
        if (temp == NULL) {
            cout << "***\n" << "LIST: []" << "\n***";
            return;
        }

        cout << "***\n" << "LIST (start to end): \n[ ";
        while(temp != NULL) {
            cout << temp -> data << ", ";
            temp = temp -> next;
        }
        cout << "]" << "\n***" << endl;
    }

    void reversePrint() {
        Node* temp = headNode;
        if (temp == NULL) {
            cout << "***\n" << "LIST: []" << "\n***";
            return;
        }

        // go to last Node
        while (temp -> next != NULL) {
            temp = temp -> next;
        }

        cout << "***\n" << "LIST (end to start): \n[ ";
        while(temp != NULL) {
            cout << temp -> data << ", ";
            temp = temp -> prev;
        }
        cout << "]" << "\n***" << endl;
    }

};


int main() {
    DoublyLinkedList list;

    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.nsertAtHead(4);

    list.print();
    list.reversePrint();
    
    return 0;
}
