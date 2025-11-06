#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;  
    Node* prev; 
    Node* up;    
    Node* down; 

    Node(int val) {
        data = val;
        next = prev = up = down = nullptr;
    }
};

Node* constructDoublyLinkedMatrix(vector<vector<int>>& mat, int n, int m) {
    if (n == 0 || m == 0)
        return nullptr;

    vector<vector<Node*>> node(n, vector<Node*>(m, nullptr));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            node[i][j] = new Node(mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 < m)
                node[i][j]->next = node[i][j + 1];
            if (j - 1 >= 0)
                node[i][j]->prev = node[i][j - 1];
            if (i + 1 < n)
                node[i][j]->down = node[i + 1][j];
            if (i - 1 >= 0)
                node[i][j]->up = node[i - 1][j];
        }
    }

    return node[0][0];
}

void displayMatrix(Node* head, int n, int m) {
    Node* rowPtr = head;
    while (rowPtr) {
        Node* colPtr = rowPtr;
        while (colPtr) {
            cout << colPtr->data << " ";
            colPtr = colPtr->next;
        }
        cout << endl;
        rowPtr = rowPtr->down;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = mat.size();
    int m = mat[0].size();

    Node* head = constructDoublyLinkedMatrix(mat, n, m);

    cout << "Matrix represented using 4-way Doubly Linked List:\n";
    displayMatrix(head, n, m);

    return 0;
}
