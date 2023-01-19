class Solution{
  private:
    void inorder(Node* root , vector<int>& in){
        if(root == NULL)
            return;
        
        inorder(root -> left , in);
        in.push_back(root -> data);
        inorder(root -> right , in);
    }
    void postOrder(Node* &root , vector<int>& in , int &index){
        if(root == NULL)
            return;
            
        postOrder(root -> left , in , index);
        postOrder(root -> right , in , index);
        root -> data = in[index++];
    }
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int>in;
        inorder(root , in);
        int index = 0;
        postOrder(root , in , index);
    }    
};