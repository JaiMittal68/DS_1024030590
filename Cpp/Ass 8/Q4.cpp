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
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool isBSTUtil(Node *root, Node *&prev)
{
    if (root == nullptr)
        return true;

    if (!isBSTUtil(root->left, prev))
        return false;

    if (prev != nullptr && root->data <= prev->data)
        return false;

    prev = root;

    return isBSTUtil(root->right, prev);
}

bool isBST(Node *root)
{
    Node *prev = nullptr;
    return isBSTUtil(root, prev);
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

    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->right = createNode(20);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << "The given binary tree IS a BST.\n";
    else
        cout << "The given binary tree is NOT a BST.\n";

    return 0;
}
