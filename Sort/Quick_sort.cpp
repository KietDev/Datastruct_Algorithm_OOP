#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *&a, int left, int right) {
    int pivot = a[right], index = left - 1;
    for(int i = left; i <= right; i++) {
        if(a[i] < pivot) {
            index++;
            Swap(a[index], a[i]);
        }
    }
    Swap(a[index + 1], a[right]);
    return index + 1;
}

void Quicksort(int *&a, int left, int right) {
    if(left <= right) {
        int pi = partition(a, left, right);
        Quicksort(a, left, pi - 1);
        Quicksort(a, pi + 1, right);
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
    Quicksort(a, 0, n - 1);
    Output(a, n);
    return 0;
}