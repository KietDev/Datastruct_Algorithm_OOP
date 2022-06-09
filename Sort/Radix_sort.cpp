#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int getmax(int *&a, int n) {
    int max = a[0];
    for(int i = 1; i < n; i++) {
        if(max < a[i])
            max = a[i];
    }
    return max;
}

void countsort(int *&a, int n, int exp) {
    int *out = new int[n];
    int *count = new int[10];
    for(int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }
    for(int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i -  1];
    }
    for(int i = n - 1; i >= 0; i--) {
        out[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for(int i = 0; i < n; i++) 
        a[i] = out[i];
}
void Radixsort(int *&a, int n) {
    int max = getmax(a, n);
    for(int exp = 1; (max / exp) > 0; exp = exp * 10) {
        countsort(a, n, exp);
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
    Radixsort(a, n);
    Output(a, n);
    return 0;
}