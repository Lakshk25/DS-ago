class node{
	    public:
	    int u , v , wt;
	    node(int first , int second , int weight){
	        u = first;
	        v = second;
	        wt = weight;
	    }
	};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static bool cmp(node a , node b){
	    return (a.wt < b.wt);
	}
	void makeSet(vector<int>& parent , vector<int>& rank , int V){
	    for(int i=0; i<V; i++){
	        parent[i] = i;
	        rank[i] = 0;
	    }
	}
	
	int findParent(vector<int> &parent , int node){
	    if(parent[node] == node){
	        return node;
	    }
	    return parent[node] = findParent(parent , parent[node]);
	}
	
	void unionSet(int u , int v , vector<int> &parent , vector<int>&rank){
	    u = findParent(parent , u);
	    v = findParent(parent , v);
	    
	    if(rank[u] < rank[v]){
	        parent[u] = v;
	    }
	    else if(rank[v] < rank[u]){
	        parent[v] = u;
	    }
	    else{
	        parent[v] = u;
	        rank[u]++;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<node> edges;
        
        for(int i=0; i<V; i++){
            int u = i;
            for(auto x : adj[i]){
                edges.push_back(node(i , x[0] , x[1]));
            }
        }
        
        sort(edges.begin() , edges.end() , cmp);
        
        vector<int> parent(V);
        vector<int> rank(V);
        makeSet(parent , rank , V);
        
        int minWeight = 0;
        for(auto i : edges){
            int x = findParent(parent , i.u);
            int y = findParent(parent , i.v);
            int wt = i.wt;
            if(x != y){
                minWeight += wt;
                unionSet(x , y , parent , rank);
            }
        }
        return minWeight;
    }
};
