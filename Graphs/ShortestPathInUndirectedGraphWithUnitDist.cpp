class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> ans(N , -1);
        
        // adjacency list
        unordered_map<int , list<int>> adj;
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // BFS
        
        vector<bool> visited(N , 0);
        queue<int> q;
        q.push(src);
        ans[src] = 0;
        visited[src] = true;
        
        while(!q.empty()){
            
            int front = q.front();
            q.pop();
            
            for(auto i : adj[front]){
                if(!visited[i]){
                    ans[i] = ans[front] + 1;
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        
        return ans;
        
    }
};