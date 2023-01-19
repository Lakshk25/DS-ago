class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    bool dfs(int node , int parent , vector<int>&dis , vector<int>&low , vector<bool>&visited , int c , int d , vector<int>adj[] , int &timer)
    {
        visited[node] = true;
        dis[node] = low[node] = timer++;
        
        for(auto nbr: adj[node]){
            if(nbr == parent){
                continue;
            }
            else if(!visited[nbr]){
                if(dfs(nbr , node , dis , low , visited , c , d , adj , timer)){
                    return true;
                }
                low[node] = min(low[node] , low[nbr]);
                
                // check edge is a bridge
                if(low[nbr] > dis[node]){
                    if((node == c && nbr == d) || (node == d && nbr == c))
                        return true;
                }
            }
            else{
                // node already visited and not parent
                // back edge
                low[node] = min(low[node] , dis[nbr]);
            }
        }
        return false;
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int>dis(V , -1);
        vector<int>low(V , -1);
        vector<bool>visited(V , 0);
        int timer = 0;
        vector<pair<int , int>>ans;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i , -1 , dis , low , visited , c , d , adj , timer))
                    return 1;
            }
        }
        return 0;
    }
};