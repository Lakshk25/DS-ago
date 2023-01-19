class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void sort(int node , vector<bool>&visited , stack<int> &s , vector<int> adj[]){
	    
	    visited[node] = 1;
	    for(auto neighbour : adj[node]){
	        if(!visited[neighbour]){
	            sort(neighbour , visited , s , adj);
	        }
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V , 0);
	    stack<int> s;
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i])
	            sort(i , visited , s , adj);
	    }
	    
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};