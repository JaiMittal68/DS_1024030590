#include <iostream>
using namespace std;

#define MAX 5

int list[MAX];
int front = -1, rear = -1;

bool isFull()
{
    return (rear == MAX - 1);
}

bool isEmpty()
{
    return (front == -1 || front > rear);
}

void enqueue(int value)
{
    if (isFull())
    {
        cout << "list is Full! Cannot insert.\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    list[rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "list is Empty! Cannot delete.\n";
        return;
    }

    cout << "Deleted: " << list[front] << endl;
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

void peek()
{
    if (isEmpty())
    {
        cout << "list is Empty! Nothing to peek.\n";
    }
    else
    {
        cout << "Front Element: " << list[front] << endl;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "list is Empty.\n";
        return;
    }

    cout << "list Elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n----- MENU -----\n";
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
                cout << "list is Empty.\n";
            else
                cout << "list is NOT Empty.\n";
            break;

        case 5:
            if (isFull())
                cout << "list is Full.\n";
            else
                cout << "list is NOT Full.\n";
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
