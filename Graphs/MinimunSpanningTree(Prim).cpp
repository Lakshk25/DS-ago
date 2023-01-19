
// bif(n^2)
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<int> key(V);
        vector<bool> mst(V);
        vector<int> parent(V);
        
        for(int i=0; i<V; i++){
            key[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }
        
        key[0] = 0;
        parent[0] = -1;
        
        for(int i=0; i<V; i++){
            int mini = INT_MAX;
            int u;
            
            // find the min node
            for(int j=0; j<V; j++){
                if(mst[j] == false && key[j] < mini){
                    u = j;
                    mini = key[j];
                }
            }
            
            // mark min node as true
            
            mst[u] = true;
            
            // check its adjacent nodes
            for(auto it : adj[u]){
                int v = it[0];
                int w = it[1];
                if(mst[v] == false && w < key[v]){
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
        int weight = 0;
        for(int i=1; i<V; i++){
            weight += key[i];
        }
        return weight;
    }
};


// big(nlog(n))

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vist(V, 0);
        int sum = 0;
        // {wt, node}
        pq.push({0, 0}); // we are only keeping track of weight and node and not the parent
        // as we only have to retrun the sum and not the edges in MST.
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(vist[node] == 1) continue; // if already visisted
            vist[node] = 1; // else mark it visited only after popping out of the min-heap
            
            sum += wt; // add the edge weight to sum
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgwt = it[1];
                
                if(!vist[adjNode])
                    pq.push({edgwt, adjNode});
            }
        }
        
        return sum;
    }
};