class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // assign max value to add nodes
        vector<int> dist(V , INT_MAX);
        
        // set of(distance , node)
        set<pair<int , int>> st;
        
        // initialise distance and set with source node
        dist[S] = 0;
        st.insert(make_pair(0 , S));
        
        while(!st.empty()){
            
            // get top record
            auto top = *(st.begin());
            
            int nodeDistance = top.first;
            int topNode = top.second;
            
            // remove top record
            st.erase(st.begin());
            
            // traverse neighbours
            
            for(auto neighbour : adj[topNode]){
                int adjNode = neighbour[0];
                int edgeWeight = neighbour[1];
                
                if(nodeDistance + edgeWeight < dist[adjNode]){
                    
                    auto record = st.find(make_pair(dist[adjNode] , adjNode));
                    // if found
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    // update distance
                    dist[adjNode] = nodeDistance + edgeWeight;
                    // record push in set
                    st.insert(make_pair(dist[adjNode] , adjNode));
                }
            }
        }
        return dist;
    }
};