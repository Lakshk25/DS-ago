#include <iostream>
#include <stack>
#include <list>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    void dfs(int node , unordered_map<int, bool> &visited , stack<int> &s){
        visited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first , visited , s);
            }
        }
        s.push(node);
    }
    void topologicalSort(graph &g , stack<int>& s)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < 6; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, s);
            }
        }
    }

    void shortestPath(int src , vector<int> &dist , stack<int>& s){
        dist[src] = 0;

        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};
int main()
{
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.printAdj();
    stack<int> s;
    int src = 1;
    vector<int> dist(6);
    for (int i = 0; i < 6; i++)
    {
        dist[i] = INT_MAX;
    }
    g.topologicalSort(g , s);
    g.shortestPath(src , dist , s);

    cout<<"Answer"<<endl;

    for(int i=0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}