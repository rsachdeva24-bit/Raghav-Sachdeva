#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cout << "Enter string:";
    getline(cin, s);
    
    queue<char> q;                
    unordered_map<char, int> freq; 

    for (char c : s) {
        q.push(c);
        freq[c]++;

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << "-1 ";
    }
    cout << endl;

    return 0; 
    
}

