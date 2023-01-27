#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

// insertion
Node *makeBST(Node *root, int data)
{
    if (root == NULL)
    {
        Node *root = new Node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = makeBST(root->left, data);
    }
    else
    {
        root->right = makeBST(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    if (data == -1)
        return;
    root = makeBST(root, data);
    takeInput(root);
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front(); // to point temp to front
        q.pop();
        if (temp == NULL)
        { // used to add next line for printing tree
            cout << endl;
            if (!q.empty())
            { // check if not empty we need to add NULL for next levels
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // if not null push
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// bool search(Node* root, int x) {
//     if(root == NULL){
//         return false;
//     }
//     if(root -> data == x){
//         return true;
//     }
//     if(x < root -> data)
//         search(root -> left , x);
//     else
//         search(root -> right , x);
// }
/*
// Iterative
bool search(Node* root, int x) {
    while(root != NULL){
        if(root -> data == x)
            return true;
        if(root -> data < x)
            root = root -> right;
        else
            root = root -> left;
    }
    return false;
}
*/

Node *minVal(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node *maxVal(Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}
Node *deleteNode(Node *root, int val)
{

    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // right child
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            Node *temp = minVal(root->right);
            int mini = temp->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, val);
        return root;
    }
    return root;
}
void inOrder(Node *root)
{ // LNR
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    Node *root = NULL;
    cout << "Enter input for BST" << endl;
    takeInput(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << endl;
    root = deleteNode(root, 10);
    levelOrderTraversal(root);
    cout << endl;
    inOrder(root);
    return 0;
}