class Solution
{
    private:
    stack<int>stk;
    
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        if(vis[node]){
            return ;
        }
        vis[node]=1;
        for(auto x:adj[node]){
            if(vis[x]==false){
                dfs(x,adj,vis);
            }
        }
        stk.push(node);
        return ;
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // ++V;
        vector<bool>vis(V,false);
        for(int i=0;i<V;++i){
            dfs(i,adj,vis);
        }
        vector<vector<int>>adjNew(V);
        for(int i=0;i<V;++i){
            for(auto x:adj[i]){
                adjNew[x].push_back(i);
            }
            vis[i]=false;
        }
        int count=0;
        while(!stk.empty()){
            auto temp=stk.top();
            stk.pop();
            if(vis[temp]==false){
                ++count;
                dfs(temp,adjNew,vis);
                // Print the SCC if required
            }
        }
        return count;
        //code here
    }
};