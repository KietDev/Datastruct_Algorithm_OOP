#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};
typedef Node* Tree;

Tree getNode(int value) {
    Tree newnode = new Node;
    if(newnode == NULL) 
        return NULL;
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}
Tree Insert(Tree root, int value) {
    if(root == NULL) 
        return getNode(value);
    if(value < root->data)
        root->left = Insert(root->left, value);
    else
        root->right = Insert(root->right, value);
    return root; 
}
Tree Search(Tree root, int value) {
    if(root == NULL)
        return NULL;
    if(root->data == value)
        return root;
    else if(root->data > value)
        return Search(root->left, value);
    else
        return Search(root->right, value);
}
Tree Remove(Tree root, int value) {
    if(root == NULL)
        return NULL;
    if(value < root->data)
        root->left = Remove(root->left, value);
    else if(value > root->data)
        root->right = Remove(root->right, value);
    else {
        if(root->left == NULL) {
            Tree temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Tree temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        } else {
            Tree parent = root, current = root->right;
            while(current->left != NULL) {
                parent = current;
                current = current->left;
            } 
            if(parent != root)
                parent->left = current->right;
            else 
                parent->right = current->right;
            root->data = current->data;
            delete current;
            return root;
        }
    }
}

void Inputtree(int &n, Tree &root) {
    cin >> n;
    int value;
    for(int i = 0; i < n; i++) {
        cin >> value;
        root = Insert(root, value);
    }
}

void NLR(Tree root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    NLR(root->left);
    NLR(root->right);
}
void LRN(Tree root) {
    if(root == NULL)
        return;
    LRN(root->left);
    cout << root->data << " ";
    LRN(root->right);
}

int main() {
    Tree root = NULL;
    int n;
    Inputtree(n, root);
    NLR(root);
    cout << endl;
    LRN(root);
    int k, rm;
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> rm;
        root = Remove(root, rm);
    }
    NLR(root);
    return 0;
}