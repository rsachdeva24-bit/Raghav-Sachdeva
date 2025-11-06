#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElement(int arr[], int n) {
    stack<int> st;
    int next[n]; 

    for(int i = n-1; i >= 0; i--) {

        while(!st.empty() && st.top() <= arr[i]) {

            st.pop();
        }

        if(st.empty()){

            next[i] = -1;
        }
        else{

            next[i] = st.top();
        }

        st.push(arr[i]);
    }

    cout << "Next Greater Elements:\n";
    for(int i = 0; i < n; i++) {

        cout << arr[i] << " -> " << next[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        
        cin >> arr[i];
    }

    nextGreaterElement(arr, n);
    return 0;
}
