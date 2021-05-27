// Uygur Kiran - 2021/05/17

#include <iostream>
#define MAX_SIZE  101
using namespace std;

class Stack {
public:
    int data[MAX_SIZE];
    int top = -1;

    void push(int item) {
        // catch overflow
        if (top == MAX_SIZE-1) {
            cout << "ERROR: stack overflow" << endl;
            return;
        }
        top++;
        data[top] = item;
    }

    void pop() {
        if  (top == -1) {
            cout << "ERROR: no element to pop" << endl;
            return;
        }
        top--;
    }

    int getTop() {
        return data[top];
    }

    void print() {
        cout << "STACK [" << endl;

        for (int i = 0; i <= top; i++) {
            cout << "\t" << data[i] << endl;
        }
        cout << "\t" << " ]" << endl;
    }

};

// run
int main() {
    Stack s;
    s.push(4);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(123);

    s.print();
    return 0;
};