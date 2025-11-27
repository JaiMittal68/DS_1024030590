#include <iostream>
using namespace std;

/* ===================== CIRCULAR LINKED LIST ===================== */
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

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertAtBeginning(int value)
    {
        CNode *newNode = new CNode(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            CNode *temp = head;
            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
        cout << "Inserted " << value << " at beginning (Circular).\n";
    }

    void insertAtEnd(int value)
    {
        CNode *newNode = new CNode(value);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            CNode *temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << value << " at end (Circular).\n";
    }

    void insertAfterValue(int key, int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert after " << key << ".\n";
            return;
        }

        CNode *temp = head;
        do
        {
            if (temp->data == key)
            {
                CNode *newNode = new CNode(value);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << value << " after " << key << " (Circular).\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value " << key << " not found (Circular).\n";
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

        CNode *prev = head;
        CNode *curr = head->next;

        while (curr != head && curr->data != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head)
        {
            cout << "Value " << key << " not found (Circular).\n";
            return;
        }

        CNode *newNode = new CNode(value);
        newNode->next = curr;
        prev->next = newNode;

        cout << "Inserted " << value << " before " << key << " (Circular).\n";
    }

    void deleteByValue(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete " << key << ".\n";
            return;
        }

        CNode *curr = head;
        CNode *prev = nullptr;

        if (head->data == key)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
                cout << "Deleted node " << key << " (Circular).\n";
                return;
            }

            CNode *last = head;
            while (last->next != head)
                last = last->next;

            CNode *temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            cout << "Deleted node " << key << " (Circular).\n";
            return;
        }

        prev = head;
        curr = head->next;

        while (curr != head && curr->data != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head)
        {
            cout << "Value " << key << " not found (Circular).\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Deleted node " << key << " (Circular).\n";
    }

    void search(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty (Circular).\n";
            return;
        }

        CNode *temp = head;
        int pos = 1;
        do
        {
            if (temp->data == key)
            {
                cout << "Value " << key << " found at position " << pos << " (Circular).\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Value " << key << " not found (Circular).\n";
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty (Circular).\n";
            return;
        }

        CNode *temp = head;
        cout << "Circular List: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList()
    {
        if (head == nullptr)
            return;

        CNode *temp = head->next;
        while (temp != head)
        {
            CNode *next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
        head = nullptr;
    }
};

/* ===================== DOUBLY LINKED LIST ===================== */

class DNode
{
public:
    int data;
    DNode *prev;
    DNode *next;

    DNode(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DNode *head;
    DNode *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertAtBeginning(int value)
    {
        DNode *newNode = new DNode(value);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at beginning (Doubly).\n";
    }

    void insertAtEnd(int value)
    {
        DNode *newNode = new DNode(value);

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
        cout << "Inserted " << value << " at end (Doubly).\n";
    }

    void insertAfterValue(int key, int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert after " << key << ".\n";
            return;
        }

        DNode *curr = head;
        while (curr != nullptr && curr->data != key)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Value " << key << " not found (Doubly).\n";
            return;
        }

        DNode *newNode = new DNode(value);
        newNode->next = curr->next;
        newNode->prev = curr;

        if (curr->next != nullptr)
        {
            curr->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }

        curr->next = newNode;

        cout << "Inserted " << value << " after " << key << " (Doubly).\n";
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

        DNode *curr = head->next;

        while (curr != nullptr && curr->data != key)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Value " << key << " not found (Doubly).\n";
            return;
        }

        DNode *newNode = new DNode(value);
        newNode->next = curr;
        newNode->prev = curr->prev;

        curr->prev->next = newNode;
        curr->prev = newNode;

        cout << "Inserted " << value << " before " << key << " (Doubly).\n";
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
            DNode *temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete temp;
            cout << "Deleted node " << key << " (Doubly).\n";
            return;
        }

        DNode *curr = head->next;
        while (curr != nullptr && curr->data != key)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Value " << key << " not found (Doubly).\n";
            return;
        }

        if (curr == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete curr;
        }
        else
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }

        cout << "Deleted node " << key << " (Doubly).\n";
    }

    void search(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty (Doubly).\n";
            return;
        }

        DNode *temp = head;
        int pos = 1;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Value " << key << " found at position " << pos << " (Doubly).\n";
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Value " << key << " not found (Doubly).\n";
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty (Doubly).\n";
            return;
        }

        DNode *temp = head;
        cout << "Doubly List (forward): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DoublyLinkedList()
    {
        DNode *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

/* ===================== MAIN MENU ===================== */

int main()
{
    CircularLinkedList clist;
    DoublyLinkedList dlist;

    int mainChoice;

    do
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Operate on Circular Linked List\n";
        cout << "2. Operate on Doubly Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (mainChoice == 1)
        {
            int choice, value, key;
            do
            {
                cout << "\n--- Circular Linked List Menu ---\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert AFTER a value\n";
                cout << "4. Insert BEFORE a value\n";
                cout << "5. Delete a node by value\n";
                cout << "6. Search for a node\n";
                cout << "7. Display list\n";
                cout << "8. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    clist.insertAtBeginning(value);
                    break;

                case 2:
                    cout << "Enter value: ";
                    cin >> value;
                    clist.insertAtEnd(value);
                    break;

                case 3:
                    cout << "Enter key (after which to insert): ";
                    cin >> key;
                    cout << "Enter value: ";
                    cin >> value;
                    clist.insertAfterValue(key, value);
                    break;

                case 4:
                    cout << "Enter key (before which to insert): ";
                    cin >> key;
                    cout << "Enter value: ";
                    cin >> value;
                    clist.insertBeforeValue(key, value);
                    break;

                case 5:
                    cout << "Enter value to delete: ";
                    cin >> key;
                    clist.deleteByValue(key);
                    break;

                case 6:
                    cout << "Enter value to search: ";
                    cin >> key;
                    clist.search(key);
                    break;

                case 7:
                    clist.display();
                    break;

                case 8:
                    cout << "Returning to Main Menu...\n";
                    break;

                default:
                    cout << "Invalid choice.\n";
                }

            } while (choice != 8);
        }
        else if (mainChoice == 2)
        {
            int choice, value, key;
            do
            {
                cout << "\n--- Doubly Linked List Menu ---\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert AFTER a value\n";
                cout << "4. Insert BEFORE a value\n";
                cout << "5. Delete a node by value\n";
                cout << "6. Search for a node\n";
                cout << "7. Display list\n";
                cout << "8. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    dlist.insertAtBeginning(value);
                    break;

                case 2:
                    cout << "Enter value: ";
                    cin >> value;
                    dlist.insertAtEnd(value);
                    break;

                case 3:
                    cout << "Enter key (after which to insert): ";
                    cin >> key;
                    cout << "Enter value: ";
                    cin >> value;
                    dlist.insertAfterValue(key, value);
                    break;

                case 4:
                    cout << "Enter key (before which to insert): ";
                    cin >> key;
                    cout << "Enter value: ";
                    cin >> value;
                    dlist.insertBeforeValue(key, value);
                    break;

                case 5:
                    cout << "Enter value to delete: ";
                    cin >> key;
                    dlist.deleteByValue(key);
                    break;

                case 6:
                    cout << "Enter value to search: ";
                    cin >> key;
                    dlist.search(key);
                    break;

                case 7:
                    dlist.display();
                    break;

                case 8:
                    cout << "Returning to Main Menu...\n";
                    break;

                default:
                    cout << "Invalid choice.\n";
                }

            } while (choice != 8);
        }
        else if (mainChoice == 3)
        {
            cout << "Exiting program...\n";
        }
        else
        {
            cout << "Invalid main choice.\n";
        }

    } while (mainChoice != 3);

    return 0;
}
