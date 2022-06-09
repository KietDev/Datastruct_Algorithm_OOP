#include<iostream>
using namespace std;
#define NULLDATA 100000

struct Node {
    int data;
    int next;
};
int M, avail;
Node Hastable[10000];

void Init() {
    cin >> M;
    for(int i = 0; i < M; i++) {
        Hastable[i].data = NULLDATA;
        Hastable[i].next = -1;
    }
    avail = M - 1;
}

int Hasing(int key) {
    return key % M;
}

bool Search(int key) {
    int index = Hasing(key);
    while(Hastable[index].data != key && index != -1)
        index = Hastable[index].next;
    if(Hastable[index].data == key)
        return true;
    return false;
}

int getempty() {
    while(Hastable[avail].data != NULLDATA)
        avail--;
    return avail;
}

void Insert(int key) {
    if(Search(key))
        return;
    int index = Hasing(key), i;
    while(Hastable[index].next != -1) 
        index = Hastable[i].next;
    if(Hastable[index].data == NULLDATA)
        Hastable[index].data = key;
    else {
        int empty = getempty();
        if(empty < 0) 
            return;
        else {
            Hastable[index].next = empty;
            Hastable[empty].data = key;
        }
    }
}

void Output() {
    for(int i = 0; i < M; i++) {
        cout << Hastable[i].data << " ";
    }
}

int main() {
    Init();
    int key, n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> key;
        Insert(key);
    }
    Output();
    return 0;
}