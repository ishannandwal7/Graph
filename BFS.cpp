// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    queue<int> q;
    q.push(0);
    vector<bool> vis(V, false);
    vector<int> ans;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ans.push_back(node);
        vis[node] = true;
        for (auto child : adj[node])
        {
            if (vis[child] == false)
            {
                vis[child] = true;
                q.push(child);
            }
        }
    }
    return ans;
}

// Time Complexity : O(N) + O(2*E) n= number of nodes , E = number of Edges
// Space Complexity : O(N)+O(N)