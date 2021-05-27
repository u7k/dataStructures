// Uygur Kiran - 2021/05/25

#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode *left;
    AVLNode *right;
    int height; // starts from 1
};

AVLNode *root = NULL;

static int calcNodeHeight(AVLNode *p) {
    int leftHeight, rightHeight;
    leftHeight = p && p->left ? p->left->height : 0;
    rightHeight = p && p->right ? p->right->height : 0;
    return (leftHeight>rightHeight ? leftHeight+1 : rightHeight+1);
}

int balanceFactor(AVLNode *p) {
    int leftHeight, rightHeight;
    leftHeight = p && p->left ? p->left->height : 0;
    rightHeight = p && p->right ? p->right->height : 0;
    return (leftHeight-rightHeight);
}

void print(AVLNode *p) {
    if (p) {
        print(p->left);
        cout << p->data << " ";
        print(p->right);
    }
}

AVLNode * leftLeftRotation(AVLNode *p) {
    AVLNode *pl = p->left;
    AVLNode *plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = calcNodeHeight(p);
    pl->height = calcNodeHeight(pl);

    if(root==p) root=pl;
    return pl;
}

AVLNode * leftRightRotation(AVLNode *p) {
    AVLNode *pl = p->left;
    AVLNode *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = calcNodeHeight(pl);
    p->height = calcNodeHeight(p);
    plr->height = calcNodeHeight(plr);

    if(root==p) root=plr;
    return plr;
}

AVLNode * rightRightRotation(AVLNode *p) {
    AVLNode *temp;
    temp = p->right;
    p->right = temp->left;
    temp->left = p;
    return temp;
}

AVLNode * rightLeftRotation(AVLNode *p) {
    AVLNode *temp;
    temp = p->right;
    p->right = leftLeftRotation(temp);
    return rightRightRotation(p);
}

AVLNode * insert(AVLNode *p, int data) {
    if(p == NULL) {
        AVLNode *t = new AVLNode();
        t->data = data;
        t->height = 1;
        t->left = t->right = NULL;
        return t; //leaf node
    }

    if(data < p->data) {
        p->left = insert(p->left, data); //lhs
    } else if(data > p->data) {
        p->right = insert(p->right, data); //rhs
    }
    // update height
    p->height = calcNodeHeight(p);

    // make rotation if needed
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
        return leftLeftRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
        return leftRightRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1) {
        return rightRightRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->left) == 1) {
        return rightLeftRotation(p);
    }
    return p;
}


// run /////////////////
int main() {
    root = insert(root,50);
    insert(root,10);
    insert(root,20);
    print(root);
    return 0;
}