
struct Node* solve(int n , int pre[] , char preLN[] , int& i){
    // base case
    if(i >= n)
        return NULL;
    
    // create node
    Node* root = new Node(pre[i++]);
    
    // check if curr node is leaf node then return
    if(preLN[i-1] == 'L')
        return root;

    // normal flow to add nodes
    root -> left = solve(n , pre , preLN , i);
    root -> right = solve(n , pre , preLN , i);
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    Node* root = new Node(pre[0]);
    
    // if first node is leaf node than only single node is present
    // then return it
    if(preLN[0] == 'L')
        return root;
    
    int i = 0;
    return solve(n , pre , preLN , i);
}
