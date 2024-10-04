
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dis(V,1e8);
        dis[S]=0;
        for(int i=0;i<V-1;++i){
            for(auto x:edges){
                if(dis[x[0]]!=1e8 &&  dis[x[0]]+x[2]<dis[x[1]]){
                    dis[x[1]]=dis[x[0]]+x[2];
                }
            }
        }
        // Check for Negative Cycle
        for(auto x:edges){
           if(dis[x[0]]!=1e8 && dis[x[0]]+x[2]<dis[x[1]]){
                    return {-1};
                }
        }
        return dis;
        
    }
};