#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

void insertBeforeAfter(int target, int value, bool after) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    if (!after && head->data == target) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " before " << target << ".\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (after && temp->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " after " << target << ".\n";
            return;
        } 
        else if (!after && temp->next != NULL && temp->next->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " before " << target << ".\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Target node not found.\n";
    delete newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "Deleted node " << temp->data << " from beginning.\n";
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL) {
        cout << "Deleted node " << head->data << " from end.\n";
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    cout << "Deleted node " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node " << value << ".\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Node " << value << " not found.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    cout << "Deleted node " << value << ".\n";
    delete toDelete;
}

void search(int value) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Node " << value << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Node " << value << " not found.\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, target;
    bool after;

    do {
        cout << "Singly Linked List Operations";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;

        case 3:
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Enter new node value: ";
            cin >> value;
            cout << "Insert (1) after or (0) before the node? ";
            cin >> after;
            insertBeforeAfter(target, value, after);
            break;

        case 4:
            deleteFromBeginning();
            break;

        case 5:
            deleteFromEnd();
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteSpecific(value);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;

        case 8:
            display();
            break;

        case 9:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
