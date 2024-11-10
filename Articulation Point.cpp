class Solution {
    private:
    vector<int>insertionTime,lowestTime;
    int timer=0;
    set<int>ans;
    void dfs(int node, int parent, vector<int> &vis, vector<int>adj[]) {
        vis[node]=1;
        ++timer;
        insertionTime[node]=timer;
        lowestTime[node]=timer;
        int children=0;
        for(auto x:adj[node]){
            if(x==parent){
                continue;
            }
            if(vis[x]==false){
                dfs(x,node,vis,adj);
                lowestTime[node]=min(lowestTime[node],lowestTime[x]);
                if(lowestTime[x]>=insertionTime[node] && parent!=-1){
                    ans.insert(node);
                }
                 ++children;
            }else{
               lowestTime[node]=min(lowestTime[node],insertionTime[x]);
            }
           
        }
        if(parent == -1 && children > 1){
            ans.insert(node);
        }
        return ;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>vis(V,false);
        insertionTime.resize(V,-1);
        lowestTime.resize(V,-1);
        for(int i=0;i<V;++i){
            if(vis[i]==false){
                dfs(i,-1,vis,adj);
            }
        }
       if(ans.size()==0){return {-1};}
        vector<int>res;
        for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }
};