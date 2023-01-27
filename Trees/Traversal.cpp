#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

    Node* build(Node* root){
        int data;
        cout<<"Enter data "<<endl;
        cin>>data;
        root = new Node(data);
        if(data == -1){
            return NULL;
        }
        cout<<"Enter data for left of "<<data<<endl;
        root -> left = build(root -> left);
        cout<<"Enter data for right of "<<data<<endl;
        root -> right = build(root -> right);
        return root;
    }
    
    // L = left  R = right  N = node (or print it)

    void inOrder(Node* root){   // LNR
        if(root == NULL){
            return ;
        }
        inOrder(root -> left);
        cout<<root->data<<" ";
        inOrder(root -> right);
    }

    void postOrder(Node* root){     // LRN
        if(root == NULL){
            return ;
        }
        postOrder(root -> left);
        postOrder(root -> right);
        cout<<root->data<<" ";
    }

    void preOrder(Node* root){      // NLR
        if(root == NULL){
            return ;
        }
        cout<<root->data<<" ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
};
int main()
{
    /*
        1
    3         5
   7 11    17
    */
    Node* root = NULL;
    root = root->build(root);
    root->inOrder(root);
    cout<<endl;
    root->postOrder(root);
    cout<<endl;
    root->preOrder(root);
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    return 0;
}