#include <iostream>
using namespace std;

class CNode
{
public:
    int data;
    CNode *next;

    CNode(int value)
    {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    CNode *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int value)
    {
        CNode *newNode = new CNode(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        CNode *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int size()
    {
        if (head == nullptr)
            return 0;

        int count = 1;
        CNode *temp = head->next;

        while (temp != head)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display()
    {
        if (head == nullptr)
            return;

        CNode *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    CircularLinkedList list;

    list.insertAtEnd(5);
    list.insertAtEnd(15);
    list.insertAtEnd(25);
    list.insertAtEnd(35);

    cout << "Circular Linked List: ";
    list.display();

    cout << "Size of Circular Linked List = " << list.size() << endl;

    return 0;
}
