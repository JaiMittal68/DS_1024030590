#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Display values and repeat head at the end
    void displayWithRepeatedHead()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;

        cout << "Output: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // Repeat head at the end
        cout << head->data << endl;
    }
};

int main()
{
    CircularLinkedList list;

    list.insertAtEnd(20);
    list.insertAtEnd(100);
    list.insertAtEnd(40);
    list.insertAtEnd(80);
    list.insertAtEnd(60);

    list.displayWithRepeatedHead();

    return 0;
}
