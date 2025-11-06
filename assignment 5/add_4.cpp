#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;

    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;
    if (k == 0) {
        temp->next = nullptr;
        return head;
    }

    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;

    newTail->next = nullptr;

    return newHead;
}

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) insert(head, i);

    cout << "Original List:\n";
    printList(head);

    int k = 2;
    head = rotateLeft(head, k);

    cout << "\nList after rotating left by " << k << " positions:\n";
    printList(head);

    return 0;
}
