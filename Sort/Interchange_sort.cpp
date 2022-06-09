#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Interchangesort(int *&a, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                Swap(a[i], a[j]);
            }
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
    Interchangesort(a, n);
    Output(a, n);
    return 0;
}