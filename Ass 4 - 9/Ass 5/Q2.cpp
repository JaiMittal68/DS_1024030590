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

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
    }

    int countAndDeleteAll(int key)
    {
        int count = 0;

        while (head != nullptr && head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->data == key)
            {

                prev->next = curr->next;
                Node *temp = curr;
                curr = curr->next;
                delete temp;
                count++;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return count;
    }

    ~SinglyLinkedList()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    SinglyLinkedList list;
    int n, val, key;

    cout << "Enter number of nodes in the list: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Enter key to count and delete: ";
    cin >> key;

    cout << "\nOriginal Linked List: ";
    list.display();

    int count = list.countAndDeleteAll(key);

    cout << "\nCount of key " << key << ": " << count << endl;
    cout << "Updated Linked List: ";
    list.display();
    cout << endl;

    return 0;
}
