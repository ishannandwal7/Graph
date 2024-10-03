//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    stack<int>st;
    void dfs(int node,vector<pair<int,int>>adj[],vector<bool>&vis){
        vis[node]=1;
        for(auto x:adj[node]){
            if(vis[x.first]==false){
                dfs(x.first,adj,vis);
            }
        }
        st.push(node);
        return ;
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int>dis(N,1e9);
        dis[0]=0;
        vector<bool>vis(N,false);
        for(int i=0;i<N;++i){
            if(vis[i]==false){
                dfs(i,adj,vis);
            }
        }
        while(!st.empty()){
            auto temp=st.top();
            st.pop();
            int D=dis[temp];
            for(auto x:adj[temp]){
                dis[x.first]=min(dis[x.first],D+x.second);
            }
        }
        for(auto &x:dis){
            if(x==1e9){
                x=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends