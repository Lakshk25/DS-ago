// topological sort using BFS


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    // store degree of in nodes
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
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        // store ans
	        ans.push_back(front);
	        
	        // update neighbour indegree
	        for(auto neighbour : adj[front]){
	            indegree[neighbour]--;
	            if(indegree[neighbour] == 0)
	                q.push(neighbour);
	        }
	    }
	    return ans;
	}
};
