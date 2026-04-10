#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create new node
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 1. Insert NOde
Node *insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// 2. Search value
Node *search(Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// 3. Pre-Oreder, In-Order, Post-Order
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// Find Min
Node *findMin(Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Find Max
Node *findMax(Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Delete Node
Node *deleteNode(Node *root, int value)
{
    if (root == NULL) return NULL;   

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if (root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *temp = findMax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    int choice, value;
    while (1)
    {
        cout << "\n*** Menu ***" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search value" << endl;
        cout << "3. Pre Order" << endl;
        cout << "4. In Order" << endl;
        cout << "5. Post Order" << endl;
        cout << "6. Delete Node" << endl;
        cout << "7. Find Maximum" << endl;
        cout << "8. Find Minimum" << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << "*Found*";
            else
                cout <<"*Not Found*\n";
            break;

        case 3:
            cout << "Preorder: ";
            preOrder(root);
            cout << endl;
            break;

        case 4:
            cout << "Inorder: ";
            inOrder(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder: ";
            postOrder(root);
            cout << endl;
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 7:
            if (root != NULL)
                cout << "Max: " << findMax(root)->data << endl;
            else
                cout << "*Tree is empty*"<<endl;
            break;

        case 8:
            if (root != NULL)
                cout << "Min: " << findMin(root)->data << endl;
            else
                cout << "Tree is empty"<< endl;
            break;

        case 9:
            return 0;

        default:
            cout << "Invalid choice"<<endl;
        }
    }
}