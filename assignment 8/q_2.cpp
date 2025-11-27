#include <iostream>
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

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMax(Node* root) {
    if (!root)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

Node* findMin(Node* root) {
    if (!root)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != nullptr)
        return findMin(node->right);

    Node* successor = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != nullptr)
        return findMax(node->left);

    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

void inorder(Node* root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of elements in BST: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nIn-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "\nEnter element to search (Recursive): ";
    cin >> val;
    Node* res = searchRecursive(root, val);
    if (res)
        cout << val << " found (recursive)\n";
    else
        cout << val << " not found (recursive)\n";

    cout << "\nEnter element to search (Non-Recursive): ";
    cin >> val;
    res = searchIterative(root, val);
    if (res)
        cout << val << " found (non-recursive)\n";
    else
        cout << val << " not found (non-recursive)\n";

    cout << "\nMaximum element in BST: " << findMax(root)->data;
    cout << "\nMinimum element in BST: " << findMin(root)->data << endl;

    cout << "\nEnter node value to find In-order Successor and Predecessor: ";
    cin >> val;
    Node* target = searchIterative(root, val);
    if (!target) {
        cout << "Node not found in BST.\n";
        return 0;
    }

    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);

    if (succ)
        cout << "In-order Successor of " << val << " is: " << succ->data << endl;
    else
        cout << "No In-order Successor for " << val << endl;

    if (pred)
        cout << "In-order Predecessor of " << val << " is: " << pred->data << endl;
    else
        cout << "No In-order Predecessor for " << val << endl;

    return 0;
}
