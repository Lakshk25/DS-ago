class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> distance(V , 1e8);
        distance[S] = 0;
        
        for(int i=0; i<V; i++){
            //traverse on edge list
            for(auto j : edges){
                int u = j[0];
                int v = j[1];
                int wt = j[2];
                if(distance[u]!= 1e8 && (distance[u] + wt < distance[v]))
                    distance[v] = distance[u] + wt;
            }
        }
        // check for negative cycle
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            if(distance[u] + wt < distance[v])
                return {-1};
        }
        return distance;
    }
};