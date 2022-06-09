#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Insertionsort(int *&a, int n) {
    int index, key;
    for(int i = 1; i < n; i++) {
        key = i;
        index = i - 1;
        while(index >=0 && a[index] > a[key]) {
            Swap(a[index], a[key]);
            key = index;
            index--;
        }
    }
}


void Input(int *&a, int &n) {
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Output(int *&a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int *a, n;
    Input(a, n);
    Insertionsort(a, n);
    Output(a, n);
    return 0;
}