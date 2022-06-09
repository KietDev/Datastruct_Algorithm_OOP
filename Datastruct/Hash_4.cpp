#include<iostream>
using namespace std;
#define NULLDATA -1000

int M, Hashtable[10000], n, avail;

void Init() {
    cin >> M;
    for(int i = 0; i < M; i++) {
        Hashtable[i] = NULLDATA;
    }
    n = 0;
    avail = 0;
}

int Hashing1(int key) {
    return key % M;
}

int Hashing2(int key) {
    return (M - 2) - key % (M - 2);
}

bool isFull() {
    return (n == M) ? true:false;
}

int getempty() {
    while(Hashtable[avail] != NULLDATA) {
        avail++;
    }
    return avail;
}

bool Search(int key) {
    int index1 = Hashing1(key);
    int index2 = Hashing2(key);
    int count = 1;
    while(Hashtable[index1] != key && Hashtable[index1] != NULLDATA) {
        if(count >= 15) {
            for(int i = 0; i < M; i++) {
                if(Hashtable[i] == key) {
                    return true;
                }
            }
            return false;
        }
        index1 = (index1 + index2) % M;
        count++;
    }
    if(Hashtable[index1] == key) {
        return true;
    }
    return false;
}

void Insert(int key) {
    if(isFull())
        return;
    if(Search(key))
        return;
    int index1 = Hashing1(key);
    int index2 = Hashing2(key);
    int i = index1, count = 1;
    while(Hashtable[index1] != NULLDATA) {
        if(count >= 15) {
            index1 = getempty();
            break;
        }
        index1 = (index1 + index2) % M;
        count++;
    }
    Hashtable[index1] = key;
    n++;
}

void Output() {
    for(int i = 0; i < M; i++) {
        cout << Hashtable[i] << " ";
    }
}

int main() {
    Init();
    int key, s;
    cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> key;
        Insert(key);
    }
    Output();
    return 0;
}