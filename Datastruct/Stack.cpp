#include<iostream>
using namespace std;
#define NULLDATA -10000;

class Stack {
    private:
    int *data, top;
    public:
    Stack(int = 0);
    bool isEmpty();
    bool isFull();
    void push(int key);
    int pop();
    void clear();
};
Stack::Stack(int n) {
    data = new int[n];
    top = -1;
}
bool Stack::isEmpty() {
    if(top <= -1) 
        return true;
    return false;
}
bool Stack::isFull() {
    if(top >= *(&data - 1) - data) 
        return true;
    return false;
}
void Stack::push(int key) {
    if(Stack::isFull() == true) 
        return;
    data[++top] = key;
}
int Stack::pop() {
    if(Stack::isEmpty() == true) 
        return NULLDATA;
    int temp;
    temp = data[top];
    data[top] = NULLDATA;
    top--;
    return temp;
}
void Stack::clear() {
    top = -1;
    delete []data;
}

int main() {
    int n, key;
    cin >> n;
    Stack s(n);
    for(int i = 0; i < n; i++) {
        cin >> key;
        s.push(key);
    }
    for(int i = 0; i < n; i++) {
        cout << s.pop() << " ";
    }
    return 0;
}