// Uygur Kiran - 2021/05/22
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    void enqueue(int item);
    void dequeue();
    void print();
    int getFrontValue() { return front -> data; }
    int getRearValue() { return rear -> data; }
    bool isEmpty() { return (front == NULL && rear == NULL); };
};

void Queue::enqueue(int item) {
    Node* temp = new Node();
    temp -> data = item;
    temp -> next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    // if queue not empty
    rear -> next = temp;
    rear = temp;
}

void Queue::dequeue() {
    Node* temp = front;
    if (front == NULL) return;
    // when only 1 item exists
    if (front == rear) {
        front = rear = NULL;
        return;
    }
    front = front -> next;
    delete temp;
}

void Queue::print() {
    Node* temp = front;
    cout << endl << "***\n" << "QUEUE: [ ";
    while(temp != NULL) {
        cout << temp -> data << ", ";
        temp = temp -> next;
    }
    cout << "]" << "\n***" << endl;
}


// run /////////////
int main() {
    Queue *dispatch = new Queue();
    cout << endl << dispatch -> isEmpty() << endl;

    dispatch -> enqueue(3);
    dispatch -> enqueue(4);
    dispatch -> enqueue(5);
    dispatch -> print();
    dispatch -> dequeue();
    dispatch -> print();
    dispatch -> enqueue(6);
    dispatch -> enqueue(7);
    dispatch -> print();

    cout << endl << dispatch -> isEmpty() << endl;
    cout << endl << dispatch -> getFrontValue() << endl;
    cout << endl << dispatch -> getRearValue() << endl;

    return 0;
}