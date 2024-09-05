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
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        for (int i = 0; i < V; ++i)
        {
            if (vis[i] == false)
            {
                DFS(i, adj, vis);
            }
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(2*E) n= number of nodes , E = number of Edges : undirected , for Directed the 2*E will Vary 
// Space Complexity : O(N)+O(N)+O(N) 