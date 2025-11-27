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

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            cout << "Inserted " << value << " as the first node.\n";
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at the end.\n";
    }

    void insertAfterValue(int key, int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert after " << key << ".\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value " << key << " not found in the list.\n";
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Inserted " << value << " after " << key << ".\n";
    }

    void insertBeforeValue(int key, int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert before " << key << ".\n";
            return;
        }

        if (head->data == key)
        {
            insertAtBeginning(value);
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr && curr->data != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Value " << key << " not found in the list.\n";
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = curr;
        prev->next = newNode;

        cout << "Inserted " << value << " before " << key << ".\n";
    }

    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        cout << "Deleted node with value " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (head->next == nullptr)
        {
            cout << "Deleted node with value " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;

        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        cout << "Deleted node with value " << curr->data << " from end.\n";
        delete curr;
    }

    void deleteByValue(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete " << key << ".\n";
            return;
        }

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            cout << "Deleted node with value " << key << ".\n";
            delete temp;
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr && curr->data != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Value " << key << " not found in the list.\n";
            return;
        }

        prev->next = curr->next;
        cout << "Deleted node with value " << key << ".\n";
        delete curr;
    }

    void search(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        int position = 1;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Value " << key << " found at position " << position << " from head.\n";
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Value " << key << " not found in the list.\n";
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "List elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
    int choice, value, key;

    do
    {
        cout << "\n------ Singly Linked List Menu ------\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert AFTER a value\n";
        cout << "4. Insert BEFORE a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search for a value\n";
        cout << "9. Display list\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAfterValue(key, value);
            break;

        case 4:
            cout << "Enter key (before which to insert): ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertBeforeValue(key, value);
            break;

        case 5:
            list.deleteFromBeginning();
            break;

        case 6:
            list.deleteFromEnd();
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteByValue(key);
            break;

        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;

        case 9:
            list.display();
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 10);

    return 0;
}
