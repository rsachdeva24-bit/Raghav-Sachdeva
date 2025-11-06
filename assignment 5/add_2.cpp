#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (!head) {
        return nullptr;
    }

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) {
            return head; 
        }
        temp = temp->next;
    }

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next)
        head->next = reverseKGroup(next, k);

    return prev;
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

    for (int i = 1; i <= 8; i++) {
        insert(head, i);
    }

    cout << "Original List:\n";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
