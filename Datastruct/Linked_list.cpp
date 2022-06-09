#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext;
};

struct List {
    Node *pHead, *pTail;
};

void Init(List &l);                             // initialize value for linked list
Node *getNode(int key);                         // creat a node for contain key
void AddHead(List &l, Node *newnode);           // add a node into head list
void AddTail(List &l, Node *newndoe);           // add a node into final list
void RemoveHead(List &l);                       // remove a node head list
void RemoveTail(List &l);                       // remove a node final list
Node *Search(List l, int key);                 // find key in list and return location of key in list
void InsertAfter(List &l, int key, int newkey); // insert a newnode contain newkey into after node contain key in list
void InsertBefore(List &l, int key, int newkey);// insert a newnode contain newkey into before node contain key in list
void RemoveNode(List &l, int key);              // remove node contain key in list
void Displaylist(List l);                       // display all key of list

int main() {
    List l;
    Init(l);
    int n, key, option, newkey;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> key >> option;
        Node *newnode = getNode(key);
        if(option == 1) {
            AddHead(l, newnode);
        } else {
            AddTail(l, newnode);
        }
    }
    Displaylist(l);
    while(true) {
        cin >> option;
        if(option == -1) break;
        if(option == 3) {
            RemoveHead(l);
        } else if(option == 4) {
            RemoveTail(l);
        } else if(option == 5) {
            cin >> key >> newkey;
            InsertBefore(l, key, newkey);
        } else if(option == 6) {
            cin >> key >> newkey;
            InsertAfter(l, key, newkey);
        } else {
            cin >> key;
            RemoveNode(l, key);
        }
        Displaylist(l);
    }
    return 0;
}

void Init(List &l) {
    l.pHead = l.pTail = NULL;
}

Node *getNode(int key) {
    Node *newnode = new Node;
    if(newnode == NULL)
        return NULL;
    newnode->data = key;
    newnode->pNext = NULL;
    return newnode;
}

void AddHead(List &l, Node *newnode) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = newnode;
    } else {
        newnode->pNext = l.pHead;
        l.pHead = newnode;
    }
}

void AddTail(List &l, Node *newnode) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = newnode;
    } else {
        l.pTail->pNext = newnode;
        l.pTail = newnode;
    }
}

void RemoveHead(List &l) {
    if(l.pHead == NULL) {
        cout << "Can't remove node head\n";
        return;
    } else if(l.pHead == l.pTail) {
        delete l.pHead, l.pTail;
        l.pHead = l.pTail = NULL;
        return;
    }
    Node *temp = l.pHead;
    l.pHead = temp->pNext;
    temp->pNext = NULL;
    delete temp;
}

void RemoveTail(List &l) {
    if(l.pHead == NULL) {
        cout << "Can't remove node tail\n";
        return;
    } else if(l.pHead == l.pTail) {
        delete l.pHead, l.pTail;
        l.pHead = l.pTail = NULL;
        return;
    }
    for(Node *i = l.pHead; i != NULL; i = i->pNext) {
        if(i->pNext == l.pTail) {
            delete l.pTail;
            i->pNext = NULL;
            l.pTail = i->pNext;
        }
    } 
}

Node *Search(List l, int key) {
    for(Node *i = l.pHead; i != NULL; i = i->pNext) {
        if(i->data == key)
           return i;
    }
    return NULL;
}

void InsertAfter(List &l, int key, int newkey) {
    Node *temp = Search(l, key);
    if(temp == NULL) {
        cout << "Can't find key in list\n";
        return;
    }
    Node *newnode = getNode(newkey);
    if(temp->pNext == NULL) {
        AddTail(l, newnode);
    } else {
        newnode->pNext = temp->pNext;
        temp->pNext = newnode;
    }
}

void InsertBefore(List &l, int key, int newkey) {
    Node *temp = Search(l, key);
    if(temp == NULL) {
        cout << "Can't find key in list\n";
        return;
    }
    Node *newnode = getNode(newkey);
    if(temp == l.pHead) {
        AddHead(l, newnode);
    } else {
        for(Node *i = l.pHead; i != NULL; i = i->pNext) {
            if(i->pNext == temp) {
                i->pNext = newnode;
                newnode->pNext = temp;
                return;
            }
        }
    }
}

void RemoveNode(List &l, int key) {
    Node *temp = Search(l, key);
    if(temp == NULL) {
        cout << "Can't find key in list\n";
        return;
    }
    if(temp == l.pHead) {
        RemoveHead(l);
    } else if(temp == l.pTail) {
        RemoveTail(l);
    } else {
        for(Node *i = l.pHead; i != NULL; i = i->pNext) {
            if(i->pNext == temp) {
                i->pNext = temp->pNext;
                temp->pNext = NULL;
                delete temp;
                return;
            }
        }
    }
}

void Displaylist(List l) {
    if(l.pHead == NULL) {
        cout << "List is empty\n";
        return;
    }
    for(Node *i = l.pHead; i != NULL; i = i->pNext) {
        cout << i->data << " ";
    }
    cout << endl;
}