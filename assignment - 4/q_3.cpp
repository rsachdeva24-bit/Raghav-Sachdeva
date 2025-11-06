#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    
    if (n % 2 != 0) {
        cout << "Queue size must be even!\n";
        return;
    }

    int half = n / 2;
    queue<int> firsthalf;

    for (int i = 0; i < half; i++) {
        firsthalf.push(q.front());
        q.pop();
    }

    while (!firsthalf.empty()) {
        q.push(firsthalf.front());
        firsthalf.pop();

        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    

    interleave(q);

    cout << "Interleaved Queue: ";
    display(q);

    return 0;
}
