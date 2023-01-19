class Solution {
  public:
    // Function to detect cycle in an undirected graph.

    // using BFS

    
    bool travel(vector<int> adj[] , vector<bool> visited , int i){
        
        visited[i] = true;
        queue<int> q;
        q.push(i);
        unordered_map<int , int> parent;
        parent[i] = -1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto j : adj[front]){
                if(visited[j] == true && j != parent[front])
                    return true;
                    
                else if(!visited[j]){
                    q.push(j);
                    visited[j] = true;
                    parent[j] = front;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V , 0);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                bool checkCycle = travel(adj , visited , i);
                if(checkCycle == true)
                    return true;
            }
        }
        return false;
    }
};



// using DFS

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detectCycle(vector<int> adj[] , vector<bool> visited , int node , int parent){
        
        visited[node] = true;
        
        for(auto neighbour : adj[node]){
            
            if(!visited[neighbour]){
                bool check = detectCycle(adj , visited , neighbour , node);
                if(check)
                    return true;
            }
            else if(neighbour != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V , 0);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                bool checkCycle = detectCycle(adj , visited , i , -1);
                if(checkCycle == true)
                    return true;
            }
        }
        return false;
    }
};