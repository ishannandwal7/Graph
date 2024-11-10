class Solution {
    private:
    vector<int>insertionTime,lowestTime;
    vector<vector<int>>ans;
    int timer=0;
    void dfs(int node,int parent,vector<int>adj[],vector<bool>&vis){
        vis[node]=1;
        ++timer;
        insertionTime[node]=timer;
        lowestTime[node]=timer;
        for(auto x:adj[node]){
            if(vis[x]==false){
                dfs(x,node,adj,vis);
                lowestTime[node]=min(lowestTime[node],lowestTime[x]);
                //can this be an Edge??
                if(insertionTime[node]<lowestTime[x]){
                    vector<int>temp;
                    temp.push_back(node);
                    temp.push_back(x);
                    ans.push_back(temp);
                }
            }else{
                if(x!=parent){
                    lowestTime[node]=min(lowestTime[node],lowestTime[x]);
                }
            }
        }
        return ;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool>vis(n,false);
        vector<int>adj[n];
        insertionTime.resize(n,-1);
        lowestTime.resize(n,-1);
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;++i){
            if(vis[i]==0){
                dfs(i,-1,adj,vis);
            }
        }
        
    return ans;
    }
};