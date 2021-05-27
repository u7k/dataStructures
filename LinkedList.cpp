// Uygur Kiran - 2021/05/15

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* headNode = NULL;
    void insert(int x);
    void insert(int data, int pos);
    void remove(int pos);
    void print();
    void reverse();
    void reverseWithRecursion();

private:
    void recurReverse(Node* p) {
        // break cond.
        if (p -> next == NULL) {
            headNode = p;
            return;
        }
        recurReverse(p->next);

        // set last node
        Node* temp = p -> next;
        temp -> next = p; // [] -> lastNode
        p -> next = NULL; // [] -> NULL
    }
};

// insert new Node at the beginning
void LinkedList::insert(int x) {
    Node* temp = new Node();
    temp -> data = x;
    if (headNode != NULL) temp -> next = headNode;
    headNode = temp;
}

// insert new Node at any position
void LinkedList::insert(int data, int pos) {
    Node* temp1 = new Node();
    temp1 -> data = data;
    temp1 -> next = NULL;

    if (pos == 1) {
        temp1 -> next = headNode;
        headNode = temp1;
        return;
    }

    Node* temp2 = headNode;
    for (int i = 0; i < pos-2; i++) {
        temp2 = temp2 -> next;
    }

    // connect nodes (temp2 = Node* before the target pos)
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void LinkedList::remove(int pos) {
    Node* temp1 = headNode;

    // if head to be deleted
    if (pos == 1) {
        // point head to second Node
        headNode = temp1 -> next;
        delete temp1;
        return;
    }

    // find (pos-1)th Node
    for (int i = 0; i < pos-2; i++) {
        temp1 = temp1 -> next;
    }

    // Node at the target pos
    Node* temp2 = temp1 -> next;

    // change (pos-1)'s link to point (pos+1)th Node
    temp1 -> next = temp2 -> next;

    delete temp2;
}

void LinkedList::print() {
    Node* temp = headNode;

    cout << "***\n" << "LIST: [ ";
    while(temp != NULL) {
        cout << temp -> data << ", ";
        temp = temp -> next;
    }
    cout << "]" << "\n***" << endl;
}

void LinkedList::reverse() {
    Node* head = headNode;
    Node *current, *prevNd, *nextNd;
    current = head;
    prevNd = NULL;

    while (current != NULL) {
        nextNd = current -> next;  // cache next node
        current -> next = prevNd;
        prevNd = current;
        current = nextNd;
    }

    // last node ([] -> NULL will change to prevNd <- [])
    head = prevNd;
    headNode = head;
};

void LinkedList::reverseWithRecursion() {
    recurReverse(headNode);
}


// run ///////////////////
int main() {
    LinkedList list;
    cout << "*** LinkedList created.***" << endl;

    int inp = 0;
    do {
        cout << endl << "Actions: " << endl;
        cout << "1. Insert new Element" << endl;
        cout << "2. Insert new Elm. at Position" << endl;
        cout << "3. Remove Element" << endl;
        cout << "4. Reverse Linked List" << endl;
        cout << "5. Print" << endl;
        cout << "6. Exit" << endl << " > ";
        cin >> inp;

        switch (inp) {
            case 1:
                cout << "Enter Value: ";
                int n;
                cin >> n;
                list.insert(n);
                break;
            case 2:
                cout << "Enter Value: ";
                int n2,pos;
                cin >> n2;
                cout << "\nEnter Position: ";
                cin >> pos;
                list.insert(n2, pos);
                break;
            case 3:
                cout << "Enter Position: ";
                int pos2;
                cin >> pos2;
                list.remove(pos2);
                break;
            case 4:
                list.reverse();
                break;
            case 5:
                list.print();
                break;
        } //: SWITCH

    } while (inp < 6);

    return 0;
}