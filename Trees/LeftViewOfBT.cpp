/* same like top view but level is used
first for lvl and second for data
*/
vector<int> leftView(Node *root)
{
   vector<int> ans;
        if(root == NULL){
            return ans;
        }
        map<int , int> top;
        queue<pair<Node* , int>> q;
        
        q.push(make_pair(root , 0));
        
        
        while(!q.empty()){
            pair<Node* , int> temp = q.front();
            q.pop();
            Node* front = temp.first;
            int lvl = temp.second;
            
            
            if(top.find(lvl) == top.end()){
                top[lvl] = front -> data;
            }
            
            if(front -> left){
                q.push(make_pair(front -> left , lvl + 1));
            }
            
            if(front -> right){
                q.push(make_pair(front -> right , lvl + 1));
            }
        }
        for(auto i : top){
            ans.push_back(i.second);
        }
        
        return ans; 
}

/*
    Recursive

    void solve(Node* root , vector<int> &ans , int lvl){
    if(root == NULL){
        return;
    }
    
    // check level (move left so whenever we move we add level and size increase and push it)
    if(lvl == ans.size())
        ans.push_back(root -> data);
        
    solve(root -> left , ans , lvl+1);
    solve(root -> right , ans , lvl+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Recursive way
   vector<int> ans;
   int lvl = 0;
   solve(root , ans , lvl);
   return ans;
}

*/