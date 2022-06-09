#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *pNext, *pPrev;
};
struct DList {
    Node *pHead, *pTail;
};

void Init(DList &l);                               // initialize for DList
Node *getNode(int key);                            // creat a node in DList
void AddHead(DList &l, Node *newnode);             // add a node into head DList
void AddTail(DList &l, Node *newnode);             // add a node into final DList
Node *Search(DList l, int key);                    // find key in DList and return location of key in DList
void RemoveHead(DList &l);                         // remove node head DList
void RemoveTail(DList &l);                         // remove node final DList
void InsertAfter(DList &l, int key, int newkey);   // insert a newkey into after key in DList
void InsertBefore(DList &l, int key, int newkey);  // insert a newkey into before key in DList
void RemoveNode(DList &l, int key);                // remove a node in DList
void DisplayDList(DList l);                        // display all key in DList

int main() {
    DList l;
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
    DisplayDList(l);
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
        DisplayDList(l);
    }

    return 0;
}

void Init(DList &l) {
    l.pHead = l.pTail = NULL;
}

Node *getNode(int key) {
    Node *newnode = new Node;
    if(newnode == NULL) {
        return NULL;
    }
    newnode->data = key;
    newnode->pNext = newnode->pPrev = NULL;
    return newnode;
}

void AddHead(DList &l, Node *newnode) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = newnode;
    } else {
        newnode->pNext = l.pHead;
        l.pHead->pPrev = newnode;
        l.pHead = newnode;
    }
}

void AddTail(DList &l, Node *newnode) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = newnode;
    } else {
        l.pTail->pNext = newnode;
        newnode->pPrev = l.pTail;
        l.pTail = newnode;
    }
}

Node *Search(DList l, int key) {
    for(Node *i = l.pHead; i != NULL; i = i->pNext) {
        if(i->data == key) 
           return i;
    }
    return NULL;
}

void RemoveHead(DList &l) {
    if(l.pHead == NULL) {
        cout << "Can't remove head node!\n";
        return;
    } else if(l.pHead == l.pTail) {
        delete l.pHead, l.pTail;
        l.pHead = l.pTail = NULL;
        return;
    }
    Node *temp = l.pHead;
    l.pHead = temp->pNext;
    l.pHead->pPrev = NULL;
    temp->pNext = NULL;
    delete temp;
}

void RemoveTail(DList &l) {
    if(l.pHead == NULL) {
        cout << "Can't remove tail node!\n";
        return;
    } else if(l.pHead == l.pTail) {
        delete l.pHead, l.pTail;
        l.pHead = l.pTail = NULL;
        return;
    }
    Node *temp = l.pTail;
    l.pTail = temp->pPrev;
    l.pTail->pNext = NULL;
    temp->pPrev = NULL;
    delete temp;
}

void InsertAfter(DList &l, int key, int newkey) {
    Node *temp = Search(l, key);
    if(temp == NULL) {
        cout << "Can't find key in DList\n";
        return;
    }
    Node *newnode = getNode(newkey);
    if(temp == l.pTail) {
        AddTail(l, newnode);
        return;
    }
    temp->pNext->pPrev = newnode;
    newnode->pNext = temp->pNext;
    temp->pNext = newnode;
    newnode->pPrev = temp;
}

void InsertBefore(DList &l, int key, int newkey) {
    Node *temp = Search(l, key);
    if(temp == NULL) {
        cout << "Can't find key in DList\n";
        return;
    }
    Node *newnode = getNode(newkey);
    if(temp == l.pHead) {
        AddHead(l, newnode);
        return;
    }
    newnode->pNext = temp;
    temp->pPrev->pNext = newnode;
    newnode->pPrev = temp->pPrev;
    temp->pPrev = newnode;
}

void RemoveNode(DList &l, int key) {
    Node *temp = Search(l, key);
    if(temp == NULL) {
        cout << "Can't find key in DList\n";
        return;
    }
    if(l.pHead == temp) {
        RemoveHead(l);
    } else if(l.pTail == temp) {
        RemoveTail(l);
    } else {
        Node *p = temp->pNext;
        temp->pPrev->pNext = p;
        p->pPrev = temp->pPrev;
        temp->pPrev = temp->pNext = NULL;
        delete temp;
    }
}

void DisplayDList(DList l) {
    if(l.pHead == NULL) {
        cout << "List is empty!\n";
    } else {
        for(Node *i = l.pHead; i != NULL; i = i->pNext) {
            cout << i->data << " ";
        }
        cout << endl;
    }
}