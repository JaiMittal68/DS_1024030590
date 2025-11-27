#include <iostream>
using namespace std;

class DNode
{
public:
    int data;
    DNode *prev;
    DNode *next;

    DNode(int value)
    {
        data = value;
        prev = next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DNode *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int value)
    {
        DNode *newNode = new DNode(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        DNode *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    int size()
    {
        int count = 0;
        DNode *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display()
    {
        DNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Doubly Linked List: ";
    list.display();

    cout << "Size of Doubly Linked List = " << list.size() << endl;

    return 0;
}
