class Solution{
public:
    
    Node* solve(int pre[] , int size , int mini , int maxi , int& i){
        if(i >= size)
            return NULL;
        
        // it means change new node direction (left or right) 
        // current root is half leaf node (one child)
        if(pre[i] < mini || pre[i] > maxi)
            return NULL;
        
        // to create new node
        Node* root = newNode(pre[i++]);
        
        // add new node to left or right according to data
        
        // for left new node data strictly be less than curr node data
        root -> left = solve(pre , size , mini , root -> data , i);
        
        // for right new node data strictly be greater than curr node data
        root -> right = solve(pre , size , root -> data , maxi , i);
        
        return root;
    }
    Node* post_order(int pre[], int size)
    {
        int i = 0;
        return solve(pre , size , INT_MIN , INT_MAX , i);
    }
};
