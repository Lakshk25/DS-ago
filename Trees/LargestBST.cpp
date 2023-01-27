class info{
        public:
        int mini;
        int maxi;
        bool isBST;
        int size;
    };
class Solution{
    public:
    info solve(Node* root , int &ans){
        if(root == NULL){
            return {INT_MAX , INT_MIN , true , 0};
        }
        info left = solve(root -> left , ans);
        info right = solve(root -> right , ans);
        
        info currNode;
        currNode.mini = min(root -> data , left.mini);
        currNode.maxi = max(root -> data , right.maxi);
        currNode.size = left.size + right.size + 1;
        if(left.isBST && right.isBST && root -> data > left.maxi && root -> data < right.mini)
            currNode.isBST = true;
        else
            currNode.isBST = false;
            
        if(currNode.isBST)
            ans = max(currNode.size , ans);
        
        return currNode;
        
    }
    int largestBst(Node *root)
    {
    	info ans;
    	int size = 0;
    	ans = solve(root , size);
    	return size;
    }
};