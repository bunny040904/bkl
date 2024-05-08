#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

int findMaxDepth(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int leftDepth = findMaxDepth(root->left);
        int rightDepth = findMaxDepth(root->right);

        if (leftDepth > rightDepth)
        {
            return leftDepth + 1;
        }
        else
        {
            return rightDepth + 1;
        }
    }
}

Node *createNode(int item)
{
    Node *newNode = new Node();
    newNode->key = item;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to perform inorder traversal of BST
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to insert a new key in the BST
Node *insert(Node *node, int key)
{
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// Function to search for a key in the BST
int search(Node *root, int key)
{
    if (root == nullptr || root->key == key)
        return root == nullptr ? -1 : root->key;

    if (root->key < key)
        return search(root->right, key);
    else
        return search(root->left, key);
}
void menu(Node *root)
{
    int ch;
    cout <<endl<< "1. Display Preorder of tree " << endl;
    cout << "2. Search Element in tree " << endl;
    cout << "3. No.of nodes in longest path " << endl<<endl;
    cin >> ch;
    if (ch == 1)
    {
        inorder(root);
    }
    else if (ch == 2)
    {
        cout << "\nEnter the integer to search: ";
        int key;
        cin >> key;
        int result = search(root, key);
        if (result == -1)
            cout << key << " not found in the BST." << endl;
        else
            cout << key << " found in the BST." << endl;
    }
    else{
         cout << "No of nodes in the longest path : " << findMaxDepth(root) << endl;
    }
}
int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    while(true)
    {
        menu(root);
    }
}