// Uygur Kiran - 2021/05/22

#include <iostream>
using namespace std;

///////////////////
// TREE NODE
///////////////////
struct Node {
    Node *lChild;
    int data;
    Node *rChild;
};

///////////////////
// QUEUE TO HOLD THE TREE
///////////////////
class Queue {
private:
    int size;
    Node **nodes;
    int front;
    int rear;
public:
    Queue() {
        size = 50;
        nodes = new Node*[size];
        front = rear = -1;
    }
    Queue(int ofSize) {
        size = ofSize;
        nodes = new Node*[size];
        front = rear = -1;
    }
    ~Queue() { delete []nodes; }

    void enqueue(Node *item);
    Node* dequeue();
    void print();
    Node* getFront() { return nodes[front+1]; }
    Node* getRear() { return nodes[rear]; }
    bool isEmpty() { return front == rear; }
};

void Queue::enqueue(Node* item) {
    if (rear==size-1) {
        cout << "Error: new element exceeds size of the queue." << endl;
        return;
    }
    rear++;
    nodes[rear] = item;
}

Node* Queue::dequeue() {
    Node* temp = NULL;

    if (front==rear) {
        cout << "queue is already empty." << endl;
        return temp;
    }

    temp = nodes[front+1];
    front++;
    return temp;
}

void Queue::print() {
    cout << "QUEUE: [";
    for (int i = front+1; i <= rear; i++) {
        cout << nodes[i];
        if (i != rear) { cout << ", "; }
    }
    cout << "]" << endl;
}

///////////////////
// TREE
///////////////////
class Tree {
private:
    Node *root;
public:
    int queueSize;
    Tree() {
        root = NULL;
        queueSize = 100;
    }
    Tree(int queueSizeOf) {
        queueSize = queueSizeOf;
    }

    void createTree();
    void preOrder(Node *nd);
    void preOrder() { return preOrder(root); }
    void postOrder(Node *nd);
    void postOrder() { return postOrder(root); }
    void inOrder(Node *nd);
    void inOrder() { return inOrder(root); }
    int height(Node *root);
    int height() { return height(root); }

};

void Tree::createTree() {
    Node *p, *t;
    Queue que(queueSize);

    int val;
    cout << endl << "Enter a root value: ";
    cin >> val;

    root = new Node;
    root -> data = val;
    root -> lChild = root -> rChild = NULL;
    que.enqueue(root);

    cout << endl << "*** type -1 to stop adding children ***" << endl;
    while (!que.isEmpty()) {
        p = que.dequeue();
        cout << "Enter left child of " << p -> data << ": ";
        cin >> val;

        if (val != -1) {
            t = new Node;
            t -> data = val;
            t -> lChild = t -> rChild = NULL;
            p -> lChild = t;
            que.enqueue(t);
        }
        cout << "Enter right of " << p -> data << ": ";
        cin >> val;
        if (val != -1) {
            t = new Node;
            t -> data = val;
            t -> lChild = t -> rChild = NULL;
            p -> rChild = t;
            que.enqueue(t);
        }
    } //: WHILE
}

void Tree::preOrder(Node *nd) {
    if(nd) {
        cout << nd -> data << " ";
        preOrder(nd->lChild);
        preOrder(nd->rChild);
    }
}

void Tree::postOrder(Node *nd) {
    if(nd) {
        postOrder(nd->lChild);
        postOrder(nd->rChild);
        cout << nd -> data << " ";
    }
}

void Tree::inOrder(Node *nd) {
    if(nd) {
        inOrder(nd->lChild);
        cout << nd -> data << " ";
        inOrder(nd->rChild);
    }
}

int Tree::height(Node *root) {
    int x=0, y=0;
    if (root == 0) return 0;

    x = height(root -> lChild);
    y = height(root -> rChild);

    // farthest gives the height
    if (x>y) {
        return x+1;
    } else {
        return y+1;
    }
}


int main() {
    Tree t;
    t.createTree();

    cout << endl << "PRE-ORDER: ";
    t.preOrder();

    cout << endl << "IN-ORDER: ";
    t.inOrder();

    cout << endl << "POST-ORDER: ";
    t.postOrder();

    cout << endl << "HEIGHT: " << t.height();

    cout << endl;
    return 0;
}