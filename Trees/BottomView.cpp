class Solution {
  public:
    vector <int> bottomView(Node *root) {
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
            int hDist = temp.second;
            
            // skip to check condition just push the data update only for last level(ref: top view)
            top[hDist] = front -> data;
            
            if(front -> left){
                q.push(make_pair(front -> left , hDist - 1));
            }
            
            if(front -> right){
                q.push(make_pair(front -> right , hDist + 1));
            }
        }
        for(auto i : top){
            ans.push_back(i.second);
        }
        
        return ans; 
    }
};