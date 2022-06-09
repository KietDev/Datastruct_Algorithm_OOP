#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Shellsort(int *&a, int n) {
    for(int gap = n / 2; gap != 0; gap = gap / 2) {
        int temp = a[gap];
        for(int i = gap; i < n; i++) {
            for(int j = i; j >= gap && a[j] < a[j - gap]; j = j - gap) {
                Swap(a[j], a[j - gap]);
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
    Shellsort(a, n);
    Output(a, n);
    return 0;
}