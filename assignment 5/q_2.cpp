#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int deleteAllOccurrences(Node*& head, int key) {
    int count = 0;

    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } 
        else {
            current = current->next;
        }
    }

    return count;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 1);

    cout << "Original Linked List: ";
    display(head);

    int key = 1;
    int count = deleteAllOccurrences(head, key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display(head);

    return 0;
}
