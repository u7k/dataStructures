// Uygur Kiran - 2021/05/18

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top = NULL;
public:
    void push(int item) {
        Node* temp = new Node();
        temp -> data = item;
        temp -> next = top;
        top = temp;
    }

    void pop() {
        Node *temp;
        if (top == NULL) return;
        temp = top;
        top = top -> next;
        delete temp;
    }

    void print() {
        Node* temp = top;

        cout << endl << "STACK: [ " << endl;
        while(temp != NULL) {
            cout << "\t" << temp -> data << endl;
            temp = temp -> next;
        }
        cout << "\t" << "]" << endl;
    }

};

// run
int main() {
    Stack s;
    int inp = 0;

    do {
        cout << endl << "Operations: " << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. print" << endl;
        cout << "4. exit" << endl << " > ";
        cin >> inp;

        switch (inp) {
            case 1:
                cout << "Enter Value: ";
                int n;
                cin >> n;
                s.push(n);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.print();
                break;
        }

    } while (inp < 4);

    return 0;
}