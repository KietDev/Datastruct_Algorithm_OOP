#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int *&a, int n, int i) {
    int largest = i, left = 2 * i + 1, right = left + 1;
    if(a[left] > a[largest] && left < n)
        largest = left;
    if(a[right] > a[largest] && right < n)
        largest = right;
    if(largest != i) {
        Swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void Heapsort(int *&a, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for(int i = n - 1; i > 0; i--) {
        Swap(a[0], a[i]);
        heapify(a, i, 0);
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
    Heapsort(a, n);
    Output(a, n);
    return 0;
}