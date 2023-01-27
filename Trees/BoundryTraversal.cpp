class Solution
{
public:
    // first traverse left size nodes except leaf node
    void leftTraversal(Node *root, vector<int> &ans)
    {
        // condition to ignore leaf node
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        // push first then go left or right (store top to bottom)
        ans.push_back(root->data);
        // check if left exist or not 
        if (root->left)
        {
            leftTraversal(root->left, ans);
        }
        // else
        else
        {
            leftTraversal(root->right, ans);
        }
    }
    // traverse all leaf nodes
    void leafTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        // store only if both left and right is NULL
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }
    // for right
    void rightTraversal(Node *root, vector<int> &ans)
    {
        // condition to ignore leaf node
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        // check if right 
        if (root->right)
        {
            rightTraversal(root->right, ans);
        }
        else
        {
            rightTraversal(root->left, ans);
        }
        // store by bottom to top
        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        // first push root node then traverse
        ans.push_back(root->data);
        leftTraversal(root->left, ans);

        leafTraversal(root->left, ans);  // for left leaves
        leafTraversal(root->right, ans);    // for right leaves

        rightTraversal(root->right, ans);
        return ans;
    }
};