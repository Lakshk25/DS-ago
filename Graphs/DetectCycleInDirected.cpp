class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool detectCycle(int node , vector<int> adj[] , bool visited[] , bool dfsvisited[]){
        
        visited[node] = true;
        dfsvisited[node] = true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool check = detectCycle(neighbour , adj , visited , dfsvisited);
                if(check)
                    return true;
            }
            else if(dfsvisited[neighbour])
                return true;
        }
        dfsvisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        bool visited[V] = {0};
        bool dfsvisited[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool check = detectCycle(i , adj , visited , dfsvisited);
                if(check)
                    return true;
            }
        }
        return false;
    }
};



// using kahn (topological sort)


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V);
	    for(int i=0; i<V; i++){
	        for (auto j : adj[i])
                indegree[j]++;
	    }
	    
	    // push 0 degree node to queue
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    // BFS
	    int count = 0;
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        // store ans
	        count++;
	        
	        // update neighbour indegree
	        for(auto neighbour : adj[front]){
	            indegree[neighbour]--;
	            if(indegree[neighbour] == 0)
	                q.push(neighbour);
	        }
	    }

        // if topological sorted count is equal to number of nodes so cycle is not present
	    if(count == V)
	        return false;
	   
        // cycle is present
	    return true;
    }
};