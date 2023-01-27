class Solution{
  public:
    void inorderTraversal(struct Node *root , vector<int> &inorder){
        if(root == NULL)
            return;
        
        inorderTraversal(root -> left , inorder);
        inorder.push_back(root -> data);
        inorderTraversal(root -> right , inorder);
    }
    int isPairPresent(struct Node *root, int target)
    {
        vector<int> inorder;
        inorderTraversal(root , inorder);
        
        int i = 0;
        int j = inorder.size() - 1;
        
        while(i < j){
            if(inorder[i] + inorder[j] == target)
                return 1;
            else if(inorder[i] + inorder[j] < target)
                i++;
            else
                j--;
        }
        return 0;
    }
};