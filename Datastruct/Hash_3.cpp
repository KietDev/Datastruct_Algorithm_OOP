#include<iostream>
#include<cmath>
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

int getempty() {
    while(Hashtable[avail] != NULLDATA) {
        avail++;
    }
    return avail;
}

bool isFull() {
    return (n == M) ? true:false;
}

int Hashing(int key) {
    return key % M;
}

bool Search(int key) {
    int index = Hashing(key);
    int i = index;
    int count = 1;
    while(Hashtable[index] != NULLDATA && Hashtable[index] != key) {
        index = (i + count) % M;
        count = count + 2;
    }
    if(Hashtable[index] == key)
        return true;
    return false;
}

void Insert(int key) {
    if(isFull())
        return;
    if(Search(key))
        return;
    int index = Hashing(key);
    int i =index, count = 1, count1 = 1;
    while(Hashtable[index] != NULLDATA) {
        if(count >= 32768) {
            index = getempty();
            break;
        }
        index = (i + count) % M;
        count = pow(count1, 2);
        count1++;
    }
    Hashtable[index] = key;
    n++;
}

void Output() {
    for(int i = 0; i < M; i++) {
        cout << Hashtable[i] << " ";
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