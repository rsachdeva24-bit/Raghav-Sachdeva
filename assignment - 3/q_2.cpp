#include <iostream>
#include <stack>
using namespace std;

void reverseString(string str) {
    stack<char> s;

    
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top(); 
        s.pop();             
    }

    cout << "Reversed String: " << reversed << endl;
}

int main() {
    string str = "DataStructure";
    cout << "Original String: " << str << endl;
    reverseString(str);
    return 0;
}
