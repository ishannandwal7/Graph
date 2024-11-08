class Solution
{
    private:
    
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&stk){
        if(vis[node]){
            return ;
        }
        vis[node]=1;
        for(auto x:adj[node]){
            if(vis[x]==false){
                dfs(x,adj,vis,stk);
            }
        }
        stk.push(node);
        return ;
    }
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
        return ;
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // ++V;
        stack<int>stk;
        vector<bool>vis(V,false);
        for(int i=0;i<V;++i){
            dfs(i,adj,vis,stk);
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
            }
        }
        return count;
        //code here
    }
};