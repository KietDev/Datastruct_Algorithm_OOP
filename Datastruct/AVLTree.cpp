#include<iostream>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;
};
typedef Node* AVL;
AVL getNode(int value) {
    AVL newnode = new Node;
    if(newnode == NULL)
        return NULL;
    newnode->data = value;
    newnode->height = 1;
    newnode->left = newnode->right = NULL;
    return newnode;
}
int Heigh(AVL root) {
    if(root == NULL)
        return 0;
    return root->height;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
int getbalance(AVL root) {
    if(root == NULL)
        return 0;
    return Heigh(root->left) - Heigh(root->right);
}
AVL rightrotation(AVL root) {
    AVL t1 = root->left;
    AVL t2 = t1->right;
    t1->right = root;
    root->left = t2;
    t1->height = 1 + max(Heigh(t1->left), Heigh(t1->right));
    root->height = 1 + max(Heigh(root->left), Heigh(root->right));
    return t1;
}
AVL leftrotation(AVL root) {
    AVL t1 = root->right;
    AVL t2 = t1->left;
    t1->left = root;
    root->right = t2;
    t1->height = 1 + max(Heigh(t1->left), Heigh(t1->right));
    root->height = 1 + max(Heigh(root->left), Heigh(root->right));
    return t1;
}
AVL Insert(AVL root, int value) {
    if(root == NULL)
        return getNode(value);
    if(root->data > value)
        root->left = Insert(root->left, value);
    else 
        root->right = Insert(root->right, value);
    root->height = 1 + max(Heigh(root->left), Heigh(root->right));
    int balance = getbalance(root);
    if(balance > 1 && value < root->left->data)
        return rightrotation(root);
    if(balance < -1 && value > root->right->data)
        return leftrotation(root);
    if(balance > 1 && value > root->right->data) {
        root->right = leftrotation(root->right);
        return rightrotation(root);
    }
    if(balance < -1 && value < root->left->data) {
        root->left = rightrotation(root->left);
        return leftrotation(root);
    }
    return root;
}
AVL Remove(AVL root, int value) {
    if(root == NULL)
        return NULL;
    if(root->data > value)
        root->left = Remove(root->left, value);
    else if(root->data < value) 
        root->right = Remove(root->right, value);
    else {
        if(root->left == NULL) {
            AVL temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            AVL temp = root->left;
            delete root;
            return temp;
        } else {
            AVL parent = root, current = root->right;
            while(current->left != NULL) {
                parent = current;
                current = current->left;
            }
            if(parent == root)
                parent->right = current->right;
            else
                parent->left = current->right;
            root->data = current->data;
            delete current;
        }
    }
    root->height = 1 + max(Heigh(root->left), Heigh(root->right));
    int balance = getbalance(root);
    if(balance > 1 && getbalance(root->left) >= 0)
        return rightrotation(root);
    if(balance < -1 && getbalance(root->right) <= 0)
        return leftrotation(root);
    if(balance > 1 && getbalance(root->right) < 0) {
        root->right = leftrotation(root->right);
        return rightrotation(root);
    }
    if(balance < -1 && getbalance(root->left) > 0) {
        root->left = rightrotation(root->left);
        return leftrotation(root);
    }
    return root;
}

void Inputtree(int &n, AVL &root) {
    cin >> n;
    int value;
    for(int i = 0; i < n; i++) {
        cin >> value;
        root = Insert(root, value);
    }
}

void NLR(AVL root) {
    if(root == NULL)
        return;
    cout  << root->data << " ";
    NLR(root->left);
    NLR(root->right);
}

int main() {
    AVL root = NULL;
    int n;
    Inputtree(n, root);
    NLR(root);
    cout << endl;
    int k, value;
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> value;
        root = Remove(root, value);
    }
    NLR(root);
    return 0;
}