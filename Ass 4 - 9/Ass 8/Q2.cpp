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
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node *searchRecursive(Node *root, int key)
{
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node *searchIterative(Node *root, int key)
{
    Node *current = root;

    while (current != nullptr)
    {
        if (key == current->data)
            return current;
        else if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return nullptr;
}

Node *maxElement(Node *root)
{
    if (root == nullptr)
        return nullptr;

    Node *current = root;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}

Node *minElement(Node *root)
{
    if (root == nullptr)
        return nullptr;

    Node *current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node *inorderSuccessor(Node *root, int key)
{
    Node *current = searchIterative(root, key);
    if (current == nullptr)
        return nullptr;

    if (current->right != nullptr)
    {
        return minElement(current->right);
    }

    Node *succ = nullptr;
    Node *ancestor = root;

    while (ancestor != current)
    {
        if (current->data < ancestor->data)
        {
            succ = ancestor;
            ancestor = ancestor->left;
        }
        else
        {
            ancestor = ancestor->right;
        }
    }

    return succ;
}

Node *inorderPredecessor(Node *root, int key)
{
    Node *current = searchIterative(root, key);
    if (current == nullptr)
        return nullptr;

    if (current->left != nullptr)
    {
        return maxElement(current->left);
    }

    Node *pred = nullptr;
    Node *ancestor = root;

    while (ancestor != current)
    {
        if (current->data > ancestor->data)
        {
            pred = ancestor;
            ancestor = ancestor->right;
        }
        else
        {
            ancestor = ancestor->left;
        }
    }

    return pred;
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
    int n, x;

    cout << "Enter number of nodes to insert in BST: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nIn-order Traversal of BST: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "\nEnter key to search: ";
    cin >> key;

    Node *rec = searchRecursive(root, key);
    Node *iter = searchIterative(root, key);

    if (rec != nullptr)
        cout << "Recursive Search: Key found.\n";
    else
        cout << "Recursive Search: Key NOT found.\n";

    if (iter != nullptr)
        cout << "Iterative Search: Key found.\n";
    else
        cout << "Iterative Search: Key NOT found.\n";

    Node *minNode = minElement(root);
    Node *maxNode = maxElement(root);
    if (minNode)
        cout << "Minimum element in BST: " << minNode->data << endl;
    if (maxNode)
        cout << "Maximum element in BST: " << maxNode->data << endl;

    cout << "\nEnter key to find inorder successor & predecessor: ";
    cin >> key;

    Node *succ = inorderSuccessor(root, key);
    Node *pred = inorderPredecessor(root, key);

    if (succ)
        cout << "In-order Successor of " << key << " is: " << succ->data << endl;
    else
        cout << "In-order Successor of " << key << " does not exist.\n";

    if (pred)
        cout << "In-order Predecessor of " << key << " is: " << pred->data << endl;
    else
        cout << "In-order Predecessor of " << key << " does not exist.\n";

    return 0;
}
