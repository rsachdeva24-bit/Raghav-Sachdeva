#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;          
    int left = 2 * i + 1;     
    int right = 2 * i + 2;    

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void insert(int arr[], int &n, int value) {
    n++;                
    int i = n - 1;      
    arr[i] = value;    

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(int arr[], int &n) {
    if (n <= 0)
        return -1;
    if (n == 1) {
        n--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);

    return root;
}

int getMax(int arr[], int n) {
    if (n <= 0)
        return -1;
    return arr[0];
}

void display(int arr[], int n) {
    cout << "Priority Queue (Heap): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[100]; 
    int n = 0;   
    int choice, value;

    cout << "Priority Queue using Heap\n";
    cout << "1. Insert\n2. Delete Max\n3. Get Max\n4. Display\n5. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(arr, n, value);
                break;

            case 2:
                value = extractMax(arr, n);
                if (value == -1)
                    cout << "Queue is empty!\n";
                else
                    cout << "Deleted max element: " << value << endl;
                break;

            case 3:
                value = getMax(arr, n);
                if (value == -1)
                    cout << "Queue is empty!\n";
                else
                    cout << "Max element: " << value << endl;
                break;

            case 4:
                display(arr, n);
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
