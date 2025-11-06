#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB)
        return nullptr;

    Node* a = headA;
    Node* b = headB;

    while (a != b) {
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }

    return a;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    

    Node* common = new Node(6);
    common->next = new Node(7);

    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common;

    Node* headB = new Node(4);
    headB->next = new Node(5);
    headB->next->next = common;

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with data: " << intersection->data << endl;
    else
        cout << "No intersection found.\n";

    return 0;
}
