class Solution
{
private:
    vector<int> ans;
    void DFS(int node, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;
        ans.push_back(node);
        for (auto child : adj[node])
        {
            if (vis[child] == false)
            {
                DFS(child, adj, vis);
            }
        }
        return;
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        vector<int> adjList[V];
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (adj[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int ct = 0;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; ++i)
        {
            if (vis[i] == false)
            {
                ++ct;
                DFS(i, adjList, vis);
            }
        }
        return ct;
    }
};