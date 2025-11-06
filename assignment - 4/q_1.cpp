#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == MAX - 1);
}


void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    queue[++rear] = x;
    cout << x << " enqueued\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << queue[front] << " dequeued\n";
    front++;
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Front element: " << queue[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, val;

    do {
        cout << "Queue Menu" << endl;
        cout << "1. Enqueue" <<endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" <<endl;
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << (isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n");
            break;
        case 6:
            cout << (isFull() ? "Queue is Full\n" : "Queue is not Full\n");
            break;
        case 7:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
