#include <iostream>
#include <stack>
using namespace std;

void dailyTemperatures(int temp[], int n, int ans[]) {
    stack<int> st; 

    for(int i = n-1; i >= 0; i--) {

        while(!st.empty() && temp[st.top()] <= temp[i]) {

            st.pop();
        }

        if(st.empty()) {
            ans[i] = 0;
        }
        else{
            ans[i] = st.top() - i;
        }

        st.push(i);
    }
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temp[n], ans[n];
    cout << "Enter temperatures: ";
    for(int i = 0; i < n; i++) {
        
        cin >> temp[i];
    }

    dailyTemperatures(temp, n, ans);

    cout << "Answer array: ";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
