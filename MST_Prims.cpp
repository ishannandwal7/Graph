class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool>vis(V,false);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int sum=0;
        pq.push({0,{0,-1}});
        
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int wt= temp.first;
            int node=temp.second.first;
            int parent = temp.second.second;
            if(vis[node]==false){
                vis[node]=1;
                sum+=wt;
                for(auto x:adj[node]){
                    if(vis[x[0]]==false){
                        pq.push({x[1],{x[0],node}});
                    }
                }
            }
           
        }
        return sum;
        // code here
    }
};