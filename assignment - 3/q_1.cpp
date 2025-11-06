#include <iostream>
using namespace std;

const int MAX = 100;  


struct Stk {

    int arr[MAX];
    int top;
};

void init(Stk &s) {

    s.top = -1;
}

bool isEmpty(Stk &s) {
    return (s.top == -1);
}

bool is_full(Stk &s) {

    return (s.top == MAX - 1);
}

void push( Stk &s, int value){

    if (is_full(s)){

        cout << "Stack overflow." << endl;
    }
    else{
        s.top += 1;
        s.arr[s.top] = value;
        cout << value << " Pushed" << endl;
    }
}

int pop( Stk &s){
    if (isEmpty(s)){

        cout << "Stack underflow" << endl;
        return -1;
    }
    else{
        
        int val = s.arr[s.top];
        s.top -= 1;
        return val;
    }
}


int peek(Stk &s) {
    if (isEmpty(s)) {

        cout << "Stack is empty." << endl;
        return -1;
    } 
    else {

        return s.arr[s.top];
    }
}

void display(Stk &s) {

    if (isEmpty(s)) {
         
        cout << "Stack is empty." << endl;
    }
    else {

        cout << "Stack elements: ";
        for (int i = 0; i <= s.top; i++) {

            cout << s.arr[i] << " ";
        }

        cout << endl;
    }
}





int main() {
    Stk s;
    init(s);
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(s, value);
                break;
            case 2:
                value = pop(s);
                if (value != -1) 
                    cout << value << " popped from stack." << endl;
                break;
            case 3:
                if (isEmpty(s))
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 4:
                if (is_full(s))
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;
            case 5:
                display(s);
                break;
            case 6:
                value = peek(s);
                if (value != -1)
                    cout << "Top element is: " << value << endl;
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
