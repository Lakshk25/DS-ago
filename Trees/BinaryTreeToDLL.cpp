/*
 here we point head to inorder head 
 
 we simply do inorder traversal with tracking previous node
 
 and jaha inorder me print karte he uski jagha root node ko previous node
 
 se point karwana he or fir root and previous dono ko aage badhana he
 
 
*/


class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    Node* head = NULL;
    Node* prev = NULL;
    
    void solve(Node* root){
        if(root == NULL)
            return;
            
        solve(root -> left);
        
        // to point head (go extreme left) and point it to prev
        if(prev == NULL){
            head = root;
        }
        // normal flow to point curr left to prev and prev right to curr
        else{
            prev -> right = root;
            root -> left = prev;
        }
        // update prev to root
        prev = root;
        
        // increase root to next node
        solve(root -> right);
    }
    
    Node * bToDLL(Node *root)
    {
        if(root == NULL)
            return NULL;
        
        solve(root);
        
        return head;
    }
};