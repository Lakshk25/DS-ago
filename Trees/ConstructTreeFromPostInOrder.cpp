    void createMap(int in[], int n , map<int , int>&mapping){
        for(int i=0; i<n; i++){
            mapping[in[i]] = i;
        }
    }
    Node* solve(int in[],int post[], int n , int postOrderStart , int postOrderEnd , int &index , map<int , int>&mapping){
        if(index < 0 || postOrderStart > postOrderEnd){
            return NULL;
        }
        
        int element = post[index--];
        Node* root = new Node(element);
        int position = mapping[element];
        
        root -> right = solve(in , post , n , position + 1 , postOrderEnd , index , mapping);
        root -> left = solve(in , post , n , postOrderStart , position - 1 , index , mapping);
        return root;
    }
    Node* buildTree(int in[],int post[], int n)
    {
        
        int postOrderStart = 0;
        int postOrderEnd = n;
        int index = n-1;
        map<int , int>mapping;
        createMap(in , n , mapping);
        Node* ans = solve(in, post, n , postOrderStart , postOrderEnd-1 , index , mapping);
        return ans;
    }