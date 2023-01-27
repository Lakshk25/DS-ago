class Solution
{
public:
    //  morris traversal inorder
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *pred = curr->left;
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }
                if (pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

// morris traversal preOrder

vector<int> preOrder(Node *root)
{
    vector<int> ans;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                ans.push_back(curr->data);
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

//  post order
vector<int> postOrder(Node *root)
{
    vector<int> ans;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->right == NULL)
        {
            cout<<curr -> data<<" ";
            ans.push_back(curr->data);
            curr = curr->left;
        }
        else
        {
            Node *pred = curr->right;
            while (pred->left && pred->left != curr)
            {
                pred = pred->left;
            }
            if (pred->left == NULL)
            {
                cout<<curr -> data<<" ";
                ans.push_back(curr->data);
                pred->left = curr;
                curr = curr->right;
            }
            else
            {
                pred->left = NULL;
                curr = curr->left;
            }
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
