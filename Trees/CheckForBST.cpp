bool check(Node* root , int mini , int maxi){
        if(root == NULL)
            return true;
            
        if(root -> data > mini && root -> data < maxi){
            bool left = check(root -> left , mini , root -> data);
            bool right = check(root -> right , root -> data , maxi);
            return left && right;
        }
        else
            return false;
    }
    bool isBST(Node* root) 
    {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        return check(root , mini , maxi);
    }