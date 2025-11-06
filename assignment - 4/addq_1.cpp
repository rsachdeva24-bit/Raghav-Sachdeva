#include <iostream>
using namespace std;

void printBinary(int n) {
    for (int i = 1; i <= n; i++) {
        int num = i;
        string binary = "";
        while (num > 0) {
            binary = char((num % 2) + '0') + binary;
            num /= 2;
        }
        cout << binary;
        if (i != n) {
            cout << ", ";
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    printBinary(n);
    return 0;
}