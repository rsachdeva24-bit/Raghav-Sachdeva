#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool canSort(vector<int>& A) {
    stack<int> S;
    vector<int> B;

    int n = A.size();
    int expected = 1; 

    for (int i = 0; i < n; i++) {
        
        S.push(A[i]);

        
        while (!S.empty() && S.top() == expected) {

            B.push_back(S.top());
            S.pop();
            expected++;
        }
    }

    
    while (!S.empty() && S.top() == expected) {

        B.push_back(S.top());
        S.pop();
        expected++;
    }

    
    for (int i = 1; i < B.size(); i++) {
        if (B[i] < B[i-1]){
            return false;
        }
    }

    return (B.size() == n);
}

int main() {
    vector<int> A = {4, 1, 2, 3};  
    if (canSort(A)){

        cout << " possible to sort\n";
    }
    else{
        cout << " not possible\n";
    }
}
