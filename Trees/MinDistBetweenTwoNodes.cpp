
class Solution{
    public:
    /*
    to find min distance between nodes first find their
    lowest common ancestor , then simply find distance from
    mca to both nodes and add them 
    */
    
    // find lca
    Node* findLCA(Node* root , int a , int b){
        if(root == NULL)
            return NULL;
            
        if(root -> data == a || root -> data == b)
            return root;
        
        Node* left = findLCA(root -> left , a , b);
        Node* right = findLCA(root -> right , a , b);
        
        if(left && right)
            return root;
        else if(left == NULL && right)
            return right;
        else if(left && right == NULL)
            return left;
        else
            return NULL;
    }
    
    int findDistFromLCA(Node* root , int elem){
        // elem not found
        if(root == NULL)
            return 0;
        // elem found
        if(root -> data == elem)
            return 1;
            
        int left = findDistFromLCA(root -> left , elem);
        int right = findDistFromLCA(root -> right , elem);
        
        // if both sides are 0 means elem not found on that subtree
        if(left == 0 && right == 0)
            return 0;
        
        // if any branch is 1 means we found
        else
            return (1 + left + right);
    }
    
    int findDist(Node* root, int a, int b) {
        if(root == NULL)
            return -1;
        
        
        Node* lca = findLCA(root , a , b);
        // dist of a from lca
        int firstDist = findDistFromLCA(lca , a);
        // dist of b form lca
        int secDist = findDistFromLCA(lca , b);

        // -2 to remove lca node sum (it sums two times that's why to reduce)
        return (firstDist + secDist - 2);
    
    }
};