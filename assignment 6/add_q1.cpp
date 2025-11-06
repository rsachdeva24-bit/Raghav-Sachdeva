#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node** head_ref, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head_ref;

    if (*head_ref == nullptr) {
        *head_ref = newNode;
        newNode->next = newNode;  
        return;
    }

    Node* temp = *head_ref;
    while (temp->next != *head_ref)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head_ref;
}

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == nullptr)
        return;

    Node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    *head1_ref = head;
    if (head->next != head)
        *head2_ref = slow->next;

    fast->next = slow->next;
    slow->next = head;
}

void printList(Node* head) {
    if (head == nullptr)
        return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    for (int i = 1; i <= 7; i++)
        insertEnd(&head, i);

    cout << "Original Circular Linked List: ";
    printList(head);

    splitList(head, &head1, &head2);

    cout << "\nFirst Half: ";
    printList(head1);

    cout << "Second Half: ";
    printList(head2);

    return 0;
}
