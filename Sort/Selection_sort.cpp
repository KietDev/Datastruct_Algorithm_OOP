#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Selectionsort1(int *&a, int n) {    // sort increasing
    int min = 0;
    while(min != n - 1) {
    for(int i = min; i < n; i++) {
        if(a[i] < a[min]) {
            Swap(a[i], a[min]);
        }
    }
    min++;
    }
}

void Selectionsort2(int *&a, int n) {    // sort decreasing
    int max = 0;
    while(max != n - 1) {
        for(int i = max; i < n; i++) {
            if(a[i] > a[max]) {
                Swap(a[i], a[max]);
            }
        }
        max++;
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
    Selectionsort1(a, n);
    Output(a, n);
    Selectionsort2(a, n);
    Output(a, n);
    return 0;
}