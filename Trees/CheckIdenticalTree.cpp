/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){ // if both tree node points to NULL it is identical
            return true;
        }
        if((p == NULL && q != NULL) || (q == NULL && p != NULL)){   // else false
            return false;
        }
        else{
        bool left = isSameTree(p -> left , q -> left);  // check for left till NULL
        bool right = isSameTree(p -> right , q -> right);   // check for right till NULL
        bool value = p -> val == q -> val;  //  check root node value same or not
        if(left && right && value)  // if all three equals then identical
            return true;
        else
            return false;
        }
    }
};

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL)
            return true;
        if(r1 == NULL && r2 != NULL)
            return false;
        if(r1 != NULL && r2 == NULL)
            return false;
        if(r1 -> data != r2 -> data)
            return false;
        bool left = isIdentical(r1 -> left , r2 -> left);
        bool right = isIdentical(r1 -> right , r2 -> right);
        if(left && right)
            return true;
        return false;
    }
};