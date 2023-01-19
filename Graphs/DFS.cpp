class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void DFS(int node, vector<int> adj[], vector<int> &ans, vector<int> &visited)
    {

        // push current node
        ans.push_back(node);
        visited[node] = 1;

        // check for neighbour
        for (auto j : adj[node])
        {
            // do BFS for current neighbour to go in depth
            if (!visited[j])
                DFS(j, adj, ans, visited);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {

        vector<int> ans;
        vector<int> visited(V, 0);

        // traverse all nodes
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, adj, ans, visited);
            }
        }
        return ans;
    }
};