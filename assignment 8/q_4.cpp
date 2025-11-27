#include <iostream>
#include <climits> 
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return (isBSTUtil(root->left, minVal, root->data) &&
            isBSTUtil(root->right, root->data, maxVal));
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
   

    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    cout << "Inorder traversal of tree: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << "The given binary tree IS a BST." << endl;
    else
        cout << "The given binary tree is NOT a BST." << endl;

    return 0;
}
