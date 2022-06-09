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

int getmin(int *&a, int n) {
    int min = a[0];
    for(int i = 1; i < n; i++) {
        if(min > a[i])
            min = a[i];
    }
    return min;
}

void Countingsort(int *&a, int n) {
    int *out = new int[n];
    int max = getmax(a, n), min = getmin(a, n);
    int range = max - min + 1;
    int *count = new int[range];
    for(int i = 0; i < range; i++) {
        count[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        count[a[i] - min]++;
    }
    for(int i = 1; i < range; i++) {
        count[i] = count[i] + count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--) {
        out[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }
    for(int i = 0; i < n; i++) {
        a[i] = out[i];
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
    Countingsort(a, n);
    Output(a, n);
    return 0;
}