#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *prev;
    Node *next;

    Node(char ch)
    {
        data = ch;
        prev = next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }

    void insertAtEnd(char ch)
    {
        Node *newNode = new Node(ch);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        Node *left = head;
        Node *right = tail;

        while (left != right && left->prev != right)
        {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main()
{
    DoublyLinkedList list;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    for (char ch : s)
    {
        list.insertAtEnd(ch);
    }

    cout << "Doubly Linked List: ";
    list.display();

    if (list.isPalindrome())
        cout << "The doubly linked list is a PALINDROME.\n";
    else
        cout << "The doubly linked list is NOT a palindrome.\n";

    return 0;
}
