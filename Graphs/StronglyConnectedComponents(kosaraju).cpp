
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node , unordered_map<int , bool> &visited , stack<int> &s , vector<int> adj[]){
	    visited[node] = true;
	    for(auto nbr : adj[node]){
	        if(!visited[nbr]){
	            dfs(nbr , visited , s , adj);
	        }
	    }
	    s.push(node);
	}
	void reverseDfs(int node , unordered_map<int , bool> &visited , vector<int> adj[]){
	    visited[node] = true;
	    
	    for(auto nbr : adj[node]){
	        if(!visited[nbr])
	            reverseDfs(nbr , visited , adj);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        // topological sort
        stack<int> s;
        unordered_map<int , bool> visited;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i , visited , s , adj);
            }
        }
        // create a transpose graph
        
        vector<int> transpose[V];
        
        for(int i=0; i<V; i++){
            visited[i] = 0;
            for(auto nbr : adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        // dfs call using abouve ordering
        
        int count = 0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(!visited[top]){
                count++;
                reverseDfs(top , visited , transpose);
            }
        }
        return count;
    }
};