class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        queue<int> q;

        bool visited[V] = {0};
        ans.push_back(0);
        // push first node to ans and queue
        visited[0] = true;
        q.push(0);

        // traverse to all nodes
        while (!q.empty())
        {
            // take node
            int elem = q.front();
            q.pop();

            // add all neighbouring nodes to queue with updating node visited to true
            for (auto x : adj[elem])
            {

                if (!visited[x])
                {
                    visited[x] = true;
                    ans.push_back(x);
                    q.push(x);
                }
            }
        }
        return ans;
    }
};