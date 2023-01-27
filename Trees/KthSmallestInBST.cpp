class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int findKth(Node* root , int K , int &i){
        if(root == NULL)
            return -1;
            
        int left = findKth(root -> left , K , i);
        if(left != -1)
            return left;
        i++;
        if(i == K)
            return root -> data;
        int right = findKth(root -> right , K , i);
        return right;
        
    }
    int KthSmallestElement(Node *root, int K) {
        int ans = 0;
        ans = findKth(root , K , ans);
        return ans;
    }
};