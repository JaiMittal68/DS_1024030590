#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) { // First element
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << "Inserted " << value << " into the queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return -1;
        }

        int removed = arr[front];

        if (front == rear) { // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return removed;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Nothing to peek.\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\n---- Circular Queue Menu ----\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Check Empty\n4. Check Full\n5. Peek\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            value = q.dequeue();
            if (value != -1)
                cout << "Dequeued: " << value << "\n";
            break;

        case 3:
            cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
            break;

        case 4:
            cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT full\n");
            break;

        case 5:
            value = q.peek();
            if (value != -1)
                cout << "Front element: " << value << "\n";
            break;

        case 6:
            q.display();
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
