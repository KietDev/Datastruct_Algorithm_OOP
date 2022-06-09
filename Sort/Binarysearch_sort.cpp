#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int BinarySearch(int *&a, int key, int left, int right) {
    if(right <= left) 
        return (key > a[left]) ? left + 1:left;
    int mid = (left + right) / 2;
    if(a[mid] == key) 
        return mid + 1;
    else if(key < a[mid]) 
        return BinarySearch(a, key, left, mid - 1);
    else 
        return BinarySearch(a, key, mid + 1, right);
}

void Insertsort(int *&a, int n) {
    int index, key;
    for(int i = 1; i < n; i++) {
        index = i - 1;
        key = a[i];
        int loc = BinarySearch(a, key, 0, index);
        while(index >= loc) {
            Swap(a[index + 1], a[index]);
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
    Insertsort(a, n);
    Output(a, n);
    return 0;
}