/*Write a program to find sum of every row and every column in a two-dimensional array*/

#include <iostream>
using namespace std;

int main() {
    int a[100][100], r1, c1;

    cout << "Enter n0. of rows: ";
    cin >> r1;
    cout << "Enter no. of columns: ";
    cin >> c1;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < r1; i++) {
        int rowSum = 0;
        for (int j = 0; j < c1; j++) {
            rowSum += a[i][j];
        }
        cout << "Row " << i + 1 << " sum = " << rowSum << endl;
    }

    // Sum of each column
    cout << "\nSum of each column:\n";
    for (int j = 0; j < c1; j++) {
        int colSum = 0;
        for (int i = 0; i < r1; i++) {
            colSum += a[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << colSum << endl;
    }

    return 0;
}
