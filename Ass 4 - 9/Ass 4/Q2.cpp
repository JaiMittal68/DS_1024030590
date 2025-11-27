#include <iostream>
using namespace std;

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

bool isFull()
{
    return ((rear + 1) % MAX == front);
}

bool isEmpty()
{
    return (front == -1);
}

void enqueue(int value)
{
    if (isFull())
    {
        cout << "Circular Queue is Full! Cannot insert.\n";
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    cq[rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Circular Queue is Empty! Cannot delete.\n";
        return;
    }

    cout << "Deleted: " << cq[front] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void peek()
{
    if (isEmpty())
    {
        cout << "Circular Queue is Empty! Nothing to peek.\n";
    }
    else
    {
        cout << "Front Element: " << cq[front] << endl;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Circular Queue is Empty.\n";
        return;
    }

    cout << "Queue Elements: ";
    int i = front;

    while (true)
    {
        cout << cq[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n----- CIRCULAR QUEUE MENU -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            if (isEmpty())
                cout << "Queue is Empty.\n";
            else
                cout << "Queue is NOT Empty.\n";
            break;

        case 5:
            if (isFull())
                cout << "Queue is Full.\n";
            else
                cout << "Queue is NOT Full.\n";
            break;

        case 6:
            display();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
