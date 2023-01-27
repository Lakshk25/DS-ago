class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL){    // check null return (n1 or n2 node not found)
           return NULL;
       }
       if(root -> data == n1 || root -> data == n2){    // check if any of found return to found ancestor
           return root;         // return current node ( n1 or n2)
       }
       Node* left = lca(root -> left , n1 , n2);
       Node* right = lca(root -> right , n1 , n2);
       
        if(left != NULL && right != NULL){      // if both side is ! null it means we found both n1 and n2 and root is their ancestor
            return root;
        }
       else if(left == NULL && right != NULL){  // we found only one node on right
           return right;
       }
       else if(right == NULL && left != NULL){  // we found only one node on left   
           return left;
       }
       else{
           return NULL;     // both node are absent
       }
    }
};