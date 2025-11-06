#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100


char stackArr[MAX];
int top = -1;

void push(char c) {

    if(top < MAX-1) {

        stackArr[++top] = c;
    }
}

char pop() {

    if(top >= 0) {

        return stackArr[top--];
    }
    return '\0';
}

char peek() {

    if(top >= 0){
        return stackArr[top];
    }
    return '\0';
}

bool isEmpty() {
    return top == -1;
}


int precedence(char op) {

    if(op == '+' || op == '-') {
        return 1;
    }
    if(op == '*' || op == '/'){
         return 2;
    }
    if(op == '^'){
        return 3;
    }
    return 0;
}

void conversion(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while((ch = infix[i++]) != '\0') {

        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {

            postfix[k++] = ch;
        }

        else if(ch == '(') {

            push(ch);
        }

        else if(ch == ')') {
            while(!isEmpty() && peek() != '(') {

                postfix[k++] = pop();
            }
            pop(); 
        }
        
        else {
            while(!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    
    while(!isEmpty()) {

        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];
    
    cout << "Enter infix expression: ";
    cin >> infix;

    conversion(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
