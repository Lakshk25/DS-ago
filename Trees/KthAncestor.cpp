/*

    find kth ancestor 


*/


Node* solve(Node* root , int &k , int node){
    // if root == null node is not found so return null
    if(root == NULL){
        return NULL;
    }
    // if we found node then return it
    if(root -> data == node){
        return root;
    }
    Node* left = solve(root -> left , k , node);
    Node* right = solve(root -> right , k , node);
    
    // it means we found node on left part
    if(left != NULL && right == NULL){
        k--;    // decrease k(ancestor) value
        if(k == 0){ // if it bcoms 0 then the given node is ancestor node
            return root;
        }
        return left;
    }
    // it means we found node on right part
    if(right != NULL && left == NULL){
        k--;
        if(k == 0){
            return root;
        }
        return right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root , k , node);
    // if ans == NUll simply means node not found in tree or if ans -> data == node means node is ancestor of himself which is not posibble so return -1
    if(ans == NULL || ans -> data == node)
        return -1;
        
    return ans -> data; // if all works retuurn ancestor node
}


/*


bool solve(Node* root , int k , int node , vector<int> &path){
    if(!root){  // it means no root exist on given line so return false
        return false;
    }
    
    // we found node 
    if(root -> data == node)
        return true;
        
    bool left = solve(root -> left , k , node , path);
    bool right = solve(root -> right , k , node , path);
    
    // push all nodes data in vector and return true
    if(left || right){
        path.push_back(root -> data);
        return true;
    }
    
    // if not found on all tree nodes return false
    return false;
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    bool ans = solve(root , k , node , path);
    // if ans != NULL and vector size >= k (ancestor height)
    if(ans && path.size() >= k)
        return path[k-1];   // k -1 is root node
    
    return -1;  
}
*/