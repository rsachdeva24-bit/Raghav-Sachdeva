#include <iostream>
using namespace std;

bool isEmpty(int front, int rear) {
    return (front == -1 && front == rear);
}

bool isFull(int front, int rear, int size) {
    return ((front == 0 && rear == size - 1) || (rear + 1) % size == front);
}

void enqueue(int queue[], int &front, int &rear, int size, int x) {
    if (isFull(front, rear, size)) {
        cout << "Queue is full!" <<endl;
        return;
    }
    if (front == -1) { 
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % size;
    }
    queue[rear] = x;

    cout << x << " enqueued\n";
}

void dequeue(int queue[], int &front, int &rear, int size) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty!\n";
        return;
    }
    
    cout << queue[front] << " dequeued\n";
    if (front == rear) { 
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
    }
}

void peek(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Front element: " << queue[front] << endl;
}

void display(int queue[], int front, int rear, int size) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter size of Circular Queue: ";
    cin >> size;

    int *queue = new int[size];
    int front = -1, rear = -1;

    int choice, val;
    do {
        cout << " Circular Queue Menu";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            enqueue(queue, front, rear, size, val);
            break;
        case 2:
            dequeue(queue, front, rear, size);
            break;
        case 3:
            peek(queue, front, rear);
            break;
        case 4:
            display(queue, front, rear, size);
            break;
        case 5:
            cout << (isEmpty(front, rear) ? "Queue is Empty\n" : "Queue is not Empty\n");
            break;
        case 6:
            cout << (isFull(front, rear, size) ? "Queue is Full\n" : "Queue is not Full\n");
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    
    return 0;
}
