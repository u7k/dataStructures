// Uygur Kiran 2021/05/22
#include <iostream>
using namespace std;

template<class T>
class Queue {
private:
    int size;
    T *data;
    int front;
    int rear;
public:
    Queue() {
        size = 50;
        data = new T[size];
        front = rear = -1;
    }
    Queue(int ofSize) {
        size = ofSize;
        data = new T[size];
        front = rear = -1;
    }
    ~Queue() { delete []data; }

    void enqueue(T item);
    int dequeue();
    void print();
    int getFrontValue() { return data[front+1]; }
    int getRearValue() { return data[rear]; }
};

template<class T>
void Queue<T>::enqueue(T item) {
    if (rear==size-1) {
        cout << "Error: new element exceeds size of the queue." << endl;
        return;
    }
    rear++;
    data[rear] = item;
}

template<class T>
int Queue<T>::dequeue() {
    if (front==rear) {
        cout << "queue is already empty." << endl;
        return -1;
    }
    int temp = -1;
    temp = data[front+1];
    front++;
    return temp;
}

template<class T>
void Queue<T>::print() {
    cout << "QUEUE: [";
    for (int i = front+1; i <= rear; i++) {
        cout << data[i];
        if (i != rear) { cout << ", "; }
    }
    cout << "]" << endl;
}


// run /////////////////////
int main() {
    Queue<float> dispatch(10);
    dispatch.enqueue(111);
    dispatch.enqueue(222);
    dispatch.enqueue(333);
    dispatch.print();
    cout << endl << dispatch.dequeue() << endl;
    dispatch.print();
    dispatch.enqueue(444);
    dispatch.print();
    cout << endl << dispatch.getFrontValue();
    cout << endl << dispatch.getRearValue() << endl;

    return 0;
}