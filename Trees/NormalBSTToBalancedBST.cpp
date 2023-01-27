void inorderTraversal(Node* root , vector<int> &inorder){
        if(root == NULL)
            return;
        
        inorderTraversal(root->left , inorder);
        inorder.push_back(root->data);
        inorderTraversal(root -> right , inorder);
}
Node* inorderToBST(vector<int> &inorder , int start , int end){
    if(start > end)
        return NULL;
    int mid = start + (end - start)/2;
    Node* root = new Node(inorder[mid]);
    root -> left = inorderToBST(inorder , start , mid-1);
    root -> right = inorderToBST(inorder , mid+1 , end);
    return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<int>inorder;
	inorderTraversal(root , inorder);
	return inorderToBST(inorder , 0 , inorder.size()-1);
}