/*Implement the logic to find the matrix multiplication */

#include <iostream>
using namespace std;

int main() {
    int a[100][100],b[100][100],c[100][100];
    int r1, c1, r2, c2;
    
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1;
    cin >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2;
    cin >> c2;
    
    if (c1 != r2) {
        cout << "Matrices can't be multiplied";
        return 0;
    }
    
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];
    
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            c[i][j] = 0;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
