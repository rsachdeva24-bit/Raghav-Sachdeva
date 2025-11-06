#include <iostream>
using namespace std;

//  DOUBLY LINKED LIST 

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

void insertDoubly(DNode** head_ref, int data) {
    DNode* newNode = new DNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = newNode;
        return;
    }

    DNode* temp = *head_ref;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteEvenDoubly(DNode** head_ref) {
    DNode* temp = *head_ref;
    while (temp) {
        if (temp->data % 2 == 0) {
            DNode* toDelete = temp;

            if (temp->prev)
                temp->prev->next = temp->next;
            else
                *head_ref = temp->next; 
            if (temp->next)
                temp->next->prev = temp->prev;

            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

void displayDoubly(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// CIRCULAR LINKED LIST 

struct CNode {
    int data;
    CNode* next;
};

void insertCircular(CNode** head_ref, int data) {
    CNode* newNode = new CNode();
    newNode->data = data;
    newNode->next = *head_ref;

    if (*head_ref == nullptr) {
        *head_ref = newNode;
        newNode->next = newNode; 
        return;
    }

    CNode* temp = *head_ref;
    while (temp->next != *head_ref)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head_ref;
}

void deleteEvenCircular(CNode** head_ref) {
    if (*head_ref == nullptr)
        return;

    CNode* curr = *head_ref;
    CNode* prev = nullptr;

    while (curr->data % 2 == 0 && curr->next != *head_ref) {
        CNode* last = *head_ref;
        while (last->next != *head_ref)
            last = last->next;

        last->next = curr->next;
        *head_ref = curr->next;
        delete curr;
        curr = *head_ref;
    }

    if (curr->data % 2 == 0 && curr->next == curr) {
        delete curr;
        *head_ref = nullptr;
        return;
    }

    prev = curr;
    curr = curr->next;

    while (curr != *head_ref) {
        if (curr->data % 2 == 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void displayCircular(CNode* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}


int main() {
    DNode* dHead = nullptr;
    CNode* cHead = nullptr;

    for (int i = 1; i <= 7; i++)
        insertDoubly(&dHead, i);

    for (int i = 1; i <= 7; i++)
        insertCircular(&cHead, i);

    cout << "Original Doubly Linked List: ";
    displayDoubly(dHead);
    deleteEvenDoubly(&dHead);
    cout << "After Removing Even Nodes:   ";
    displayDoubly(dHead);

    cout << "\nOriginal Circular Linked List: ";
    displayCircular(cHead);
    deleteEvenCircular(&cHead);
    cout << "After Removing Even Nodes:     ";
    displayCircular(cHead);

    return 0;
}
