class Solution{
    public:
    void createMap(int in[], int n , map<int , int>&mapping){
        for(int i=0; i<n; i++){
            mapping[in[i]] = i;
        }
    }
    Node* solve(int in[],int pre[], int n , int preOrderStart , int preOrderEnd , int &inOrderIndex , map<int , int>&mapping){
        if(inOrderIndex >= n || preOrderStart > preOrderEnd){
            return NULL;
        }
        
        int element = pre[inOrderIndex++];
        Node* root = new Node(element);
        int position = mapping[element];
        
        root -> left = solve(in , pre , n , preOrderStart , position - 1 , inOrderIndex , mapping);
        root -> right = solve(in , pre , n , position + 1 , preOrderEnd , inOrderIndex , mapping);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        
        int preOrderStart = 0;
        int preOrderEnd = n;
        int inOrderIndex = 0;
        map<int , int>mapping;
        createMap(in , n , mapping);
        Node* ans = solve(in, pre, n , preOrderStart , preOrderEnd-1 , inOrderIndex , mapping);
        return ans;
    }
};