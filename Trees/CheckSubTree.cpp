class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool check(Node* T, Node* S){
        // check if both reach NULL means subtree
        if(T == NULL && S == NULL)
            return true;
        // if any tree node is NULL false
        if(T == NULL || S == NULL)
            return false;
        // if data is not equal
        if(T -> data != S -> data)
            return false;
            
        bool left = check(T -> left , S -> left);
        bool right = check(T -> right , S -> right);
        
        // if all three true then it's a subtree
        if(left && right)
            return true;
        return false;
    }
    bool isSubTree(Node* T, Node* S) 
    {
        // if both NULL
        if(T == NULL && S == NULL)
            return true;
        if(T == NULL || S == NULL)
            return false;
        
        // check for subtree
        if(check(T , S))
            return true;
        
        
        bool left = isSubTree(T -> left , S);
        bool right = isSubTree(T -> right , S);
        // to check for leaf nodes 
        if(left || right)
            return true;
    }
};