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
        this->left = NULL;
        this->right = NULL;
    }

    Node *build(Node *root)
    {
        int data;
        cout << "Enter data " << endl; // to use input data
        cin >> data;
        root = new Node(data); // first recursion used to input root data after it we go full left and then right
        if (data == -1)
        { // to point node to NULL (any number we can give to break)
            return NULL;
        }
        // this func call jabtak we enter data if put data = -1 then it breaks
        cout << "Enter data for left of " << data << endl;
        root->left = build(root->left);
        // after that we can add data in right
        cout << "Enter data for right of " << data << endl;
        root->right = build(root->right);
        return root;
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
};
void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}
int main()
{
    /*
        1
    3         5
   7 11    17

    */
    Node *root = NULL;
    // root = root->build(root);
    // root->levelOrderTraversal(root);
    buildFromLevelOrder(root);
    //  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    return 0;
}