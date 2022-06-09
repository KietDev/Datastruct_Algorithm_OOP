#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Bubblesort(int *&a, int n) {
    int limit = n;
    while(true) {
    for(int i = 1; i < limit; i++) {
        if(a[i] < a[i - 1]) {
            Swap(a[i], a[i - 1]);
        }
    }
    limit--;
    if(limit <= 2) break;
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
    Bubblesort(a, n);
    Output(a, n);
    return 0;
}