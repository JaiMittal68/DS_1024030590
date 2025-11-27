#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        cout << "Duplicate value " << value << " not inserted.\n";
    }

    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        cout << "Value " << key << " not found in BST.\n";
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        if (root->left == nullptr)
        {
            Node *temp = root->right;
            cout << "Deleted node " << root->data << endl;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            cout << "Deleted node " << root->data << endl;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int minDepth(Node *root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    int choice, val;

    do
    {
        cout << "\n===== BST MENU =====\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Display In-order\n";
        cout << "4. Maximum depth of BST\n";
        cout << "5. Minimum depth of BST\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;

        case 3:
            cout << "In-order Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Maximum depth (height) of BST: " << maxDepth(root) << endl;
            break;

        case 5:
            cout << "Minimum depth of BST: " << minDepth(root) << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
