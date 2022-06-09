#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void merge(int *&a, int left, int mid, int right) {
    int *sub1, *sub2, *sub;
    int n1, n2;
    n1 = mid - left + 1;
    n2 = right - mid;
    sub1 = new int[n1];
    sub2 = new int[n2];
    for(int i = 0; i < n1; i++) {
        sub1[i] = a[left + i];
    }
    for(int i = 0; i < n2; i++) {
        sub2[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, len = 0;
    sub = new int[n1 + n2];
    while(i < n1 || j < n2) {
        if(i < n1 && j >= n2) {
            while(i < n1) {
                sub[len] = sub1[i];
                i++;
                len++;
            }
            break;
        } else if(i >= n1 && j < n2) {
            while(j < n2) {
                sub[len] = sub2[j];
                j++;
                len++;
            }
            break;
        }
        if(sub1[i] > sub2[j]) {
            sub[len] = sub2[j];
            j++;
            len++;
        } else {
            sub[len] = sub1[i];
            i++;
            len++;
        }
    }
    for(int i = 0; i < (n1 + n2); i++) {
        a[left + i] = sub[i];
    }
}

void Mergesort(int *&a, int left, int right) {
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    Mergesort(a, left, mid);
    Mergesort(a, mid + 1, right);
    merge(a, left, mid, right);
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
    Mergesort(a, 0, n - 1);
    Output(a, n);
    return 0;
}