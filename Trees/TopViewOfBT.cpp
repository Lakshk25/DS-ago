/*
    top view is when looking from top nodes which are behind not visible

    top do this make mapping of hd and root->data ,
    if hd already present then skip that node


*/

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        // first for hd second for data
        map<int , int> top;
        // second for hd
        queue<pair<Node* , int>> q;
        
        q.push(make_pair(root , 0));
        
        
        while(!q.empty()){
            pair<Node* , int> temp = q.front();
            q.pop();
            Node* front = temp.first;
            int hDist = temp.second;
            
            // find func is used to find if not found it return false
            // only store if on hd no node is present 
            if(top.find(hDist) == top.end()){
                top[hDist] = front -> data;
            }
            
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