#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Shakesort(int *&a, int n) {
    int left = 0, right = n - 1;
    while(left != right) {
        for(int i = left + 1; i <= right; i++) {
            if(a[i] < a[i - 1]) 
               Swap(a[i], a[i - 1]);
        }
        right--;
        for(int i = right - 1; i >= left; i--) {
            if(a[i + 1] < a[i]) 
               Swap(a[i + 1], a[i]);
        }
        left++;
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
    Shakesort(a, n);
    Output(a, n);
    return 0;
}