#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    int size = q.size();
    q.push(x);

    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    q.pop();
}

int top() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q.front();
}

bool empty() {
    return q.empty();
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top: " << top() << endl; 
    
    cout << "Top: " << top() << endl; 
    pop();
    cout << "Top: " << top() << endl; 
}
