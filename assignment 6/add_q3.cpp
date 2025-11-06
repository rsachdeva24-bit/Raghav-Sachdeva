#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertEnd(Node** head_ref, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = newNode;
        return;
    }

    Node* temp = *head_ref;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

Node* reverseInGroups(Node* head, int k) {
    if (!head)
        return nullptr;

    Node* current = head;
    Node* nextNode = nullptr;
    Node* newHead = nullptr;
    int count = 0;

    while (current && count < k) {
        nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        newHead = current;
        current = nextNode;
        count++;
    }

    if (current != nullptr) {
        Node* restHead = reverseInGroups(current, k);
        head->next = restHead;
        if (restHead)
            restHead->prev = head;
    }

    return newHead;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 10; i++)
        insertEnd(&head, i);

    int k = 3;

    cout << "Original Doubly Linked List: ";
    display(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    display(head);

    return 0;
}
