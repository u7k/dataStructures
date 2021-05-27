// Uygur Kiran - 2021/05/22
#include <iostream>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

class BinarySearchTree {
private:
    BstNode *root;
    BstNode *inPre(BstNode *p);
    BstNode *inSucc(BstNode *p);
public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int item);
    BstNode *insert(BstNode *p, int data);
    void inorder(BstNode *p);
    void inorder() { return inorder(root); }
    BstNode *search(int item) { return search(root, item); }
    BstNode *search(BstNode *t, int item);
    BstNode *getRoot() { return root; }
    int height() { return height(root); }
    int height(BstNode *p);
    BstNode *remove(BstNode *p, int item);
    BstNode *remove(int item) { return remove(root, item); }
    int min() { return min(root); }
    int min(BstNode *p);
    int max() { return min(root); }
    int max(BstNode *p);
};

void BinarySearchTree::insert(int data) {
    BstNode *t = root;
    BstNode *r, *p;

    // if first
    if (root == NULL) {
        p = new BstNode();
        p->data = data;
        p->left = p->right = NULL;
        root = p;
        return;
    }

    while (t != NULL) {
        r = t;
        if(data < t->data) t = t->left;
        else if (data > t->data) t = t->right;
        else return;
    }

    p = new BstNode();
    p->data = data;
    p->left = p->right = NULL;

    if(data < r->data) r->left = p;
    else r->right = p;
}

BstNode * BinarySearchTree::insert(BstNode *p, int data) {
    if(p == NULL) {
        BstNode *t = new BstNode();
        t->data = data;
        t->left = t->right = NULL;
        return t; //leaf node
    }

    if(data < p->data) {
         p->left = insert(p->left, data); //lhs
    } else if(data > p->data) {
        p->right = insert(p->right, data); //rhs
    }
    return p;
}

void BinarySearchTree::inorder(BstNode *p) {
    if (p) {
        BinarySearchTree::inorder(p->left);
        cout << p->data << " ";
        BinarySearchTree::inorder(p->right);
    }
}

BstNode * BinarySearchTree::search(BstNode *t, int item) {
    while(t != NULL) {
        if(item==t->data) return t;
        else if(item < t->data) t = t->left;
        else t = t->right;
    }
    return NULL;
}

int BinarySearchTree::height(BstNode *p) {
    if(p==NULL) return 0;
    int x,y;
    x = height(p->left);
    y = height(p->right);
    return x>y ? x+1 : y+1;
}

BstNode * BinarySearchTree::inPre(BstNode *p) {
    //get rhs
    while(p && p->right!=NULL) p = p->right;
    return p;
}

BstNode * BinarySearchTree::inSucc(BstNode *p) {
    //get lhs
    while(p && p->left!=NULL) p = p->left;
    return p;
}

BstNode * BinarySearchTree::remove(BstNode *p, int item) {
    BstNode *q;
    if(p==NULL) return NULL;
    if(p->left == NULL && p->right == NULL) {
        if(p == root) root=NULL;
        delete p; //del leaf node
        return NULL;
    }

    if(item < p->data) { p->left = remove(p->left, item); }
    else if(item > p->data) { p->right = remove(p->right, item); }
    else {
        //item is found, replace it with precessor or successor
        if(height(p->left) > height(p->right)) {
            q = inPre(p->left);
            p->data = q->data;
            p->left = remove(p->left,q->data);
        } else {
            q = inSucc(p->right);
            p->data = q->data;
            p->right = remove(p->right, q->data);
        }
    }
    return p;
}

int BinarySearchTree::min(BstNode *p) {
    if (p == NULL) {
        cout << endl << "Error: Tree is empty" << endl;
    }

    BstNode *temp = p;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

int BinarySearchTree::max(BstNode *p) {
    if (p == NULL) {
        cout << endl << "Error: Tree is empty" << endl;
    }
    BstNode *temp = p;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}


// run /////////////
int main() {
    BinarySearchTree* bst = new BinarySearchTree();
    BstNode *res;
    int inp = -1;
    char inp2;

    BstNode *aRoot;
    aRoot = bst->insert(bst->getRoot(),10);
    bst->insert(aRoot, 20);
    bst->insert(aRoot, 30);
    bst->insert(aRoot, 8);
    bst->insert(aRoot, 4);

    bst->inorder(aRoot);

    cout << endl << "MIN: " << bst->min(aRoot);
    cout << endl << "MAX: " << bst->max(aRoot);

    while(true) {
        cout << endl << "Search integer: ";
        cin >> inp;
        if (cin.fail()) break;

        res = bst->search(aRoot, inp);
        if(res == NULL) {
            cout << endl << "*** ITEM NOT FOUND ***" << endl;
        } else {
            cout << endl << "*** ITEM FOUND ***" << endl;
            cout << "VALUE (INT): " <<  res->data << endl;
            if (res->left != NULL) cout << "LEFT CHILD: " << res->left->data << endl;
            else cout << "LEFT CHILD: NULL" << endl;
            if (res->right != NULL) cout << "RIGHT CHILD: " << res->right->data << endl;
            else cout << "RIGHT CHILD: NULL" << endl;

            cout << "do you want to delete this node? (y/n) ";
            cin >> inp2;
            if (cin.fail() || inp2 != 'y') {
                cin.clear();
                cin.ignore();
                continue;
            } else if (inp2 == 'y') {
                bst->remove(aRoot, res->data);
                cout << "*** ITEM DELETED ***" << endl;
                bst->inorder(aRoot);
            }
        } //: ELSE: ITEM FOUND
    } //: LOOP
    return 0;
}