#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int x) {

    if(top < MAX-1) {

        stackArr[++top] = x;
    }
}

int pop() {

    if(top >= 0) {

        return stackArr[top--];
    }
    return -1; 
}

int evaluate(char postfix[]) {
    int i = 0;
    char ch;

    while((ch = postfix[i++]) != '\0') {

        if(ch >= '0' && ch <= '9') {

            push(ch - '0'); 
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch(ch) {
                case '+': 
                push(val1 + val2); 
                break;

                case '-': 
                push(val1 - val2);
                break;

                case '*':
                push(val1 * val2); 
                break;
                
                case '/': 
                push(val1 / val2); 
                break;
            }
        }
    }

    return pop(); 
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluate(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
