#include<iostream>
using namespace std;
#define NULLDATA -10000

int M, Hastable[10000], n;

void Init() {
    cin >> M;
    for(int i = 0; i < M; i++) {
        Hastable[i] = NULLDATA;
    }
    n = 0;
}

bool isFull() {
    if(n == M) {
        return true;
    }
    return false;
}

int Hasing(int key) {
    return key % M;
}

bool Search(int key) {
    int index = Hasing(key);
    while(Hastable[index] != key && Hastable[index] != NULLDATA) {
        index = index + 1;
        if(index >= M)
            index = index - M;
    }
    if(Hastable[index] == key)
        return true;
    return false;
}

void Insert(int key) {
    if(isFull() == true)
        return;
    int index = Hasing(key);
    if(Search(key))
        return;
    while(Hastable[index] != NULLDATA) {
        index = index + 1;
        if(index >= M)
            index = index - M;
    }
    Hastable[index] = key;
    n++;
}

void Output() {
    for(int i = 0; i < M; i++) {
        cout << Hastable[i] << " ";
    }
}


int main() {
    Init();
    int value, s;
    cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> value;
        Insert(value);
    }
    Output();
    return 0;
}