#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int minEle;

void push(int x) {

    if (st.empty()) {

        st.push(x);
        minEle = x;
    } 
    else if (x >= minEle) {

        st.push(x);
    } 
    else {

        st.push(2LL * x - minEle);
        minEle = x;
    }
}

void pop() {
    if (st.empty()) {

        cout << "Stack is empty\n";
        return;
    }
    int t = st.top();
    st.pop();
    if (t < minEle) {
        minEle = 2LL * minEle - t;
    }
}

// Top element
int top() {
    if (st.empty()) {

        cout << "Stack is empty\n";
        return -1;
    }
    int t = st.top();

    if (t >= minEle) {
        return t;
    }
    else{
        return minEle; 
    }
}

// Get minimum element
int getMin() {
    if (st.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return minEle;
}

int main() {

    push(4);
    push(7);
    cout << "Min: " << getMin() << endl; 
    push(3);
    push(8);
    cout << "Min: " << getMin() << endl; 
    pop();
    cout << "Min: " << getMin() << endl; 
    cout << "Top: " << top() << endl;    
}
