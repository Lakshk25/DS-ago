vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();    // check how many nodes present on current level
            vector<int> ans(size);  
            for(int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
                int index;
                if(leftToRight){
                    index = i;
                }
                else{
                    index = size - i -1;
                }
                ans[index] = node -> data;
                
                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
            }
            leftToRight = !leftToRight;
            for(auto i : ans){
                result.push_back(i);
            }
        }
        return result;
    }