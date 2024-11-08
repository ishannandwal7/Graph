class DSU{
    private:
    vector<int>size,parent;
    int nodes;
    public:
    DSU(int nodes){
        this->nodes=nodes;
        size.resize(nodes+1,1);
        parent.resize(nodes+1);
        for(int i=0;i<=nodes;++i){
            parent[i]=i;
        }
    }
    
    int findParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        if(ultimateParentU==ultimateParentV){return ;}
        if(size[ultimateParentU]<=size[ultimateParentV]){
            parent[ultimateParentU]=ultimateParentV;
            size[ultimateParentV]+=size[ultimateParentU];
        }else{
            parent[ultimateParentV]=ultimateParentU;
            size[ultimateParentU]+=size[ultimateParentV];
        }
        return ;
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DSU dsu(V);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        // vector<pair<int,pair<int,int>>>arr;
        
        for(int i=0;i<V;++i){
            for(auto x:adj[i]){
                pq.push({x[1],{i,x[0]}});
            }
        }
        // sort(begin(arr),end(arr));
        int ans=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int u=temp.second.first,v=temp.second.second,wt=temp.first;
            int parentU = dsu.findParent(u);
            int parentV = dsu.findParent(v);
           
            //  cout<<dsu.findParent(u)<<" "<<dsu.findParent(v)<<"\n";
            if(dsu.findParent(u)!=dsu.findParent(v)){
                // cout<<wt<<" "<<u<<" "<<v<<"\n";
                dsu.unionBySize(u,v);
                // cout<<dsu.findParent(u)<<" "<<dsu.findParent(v)<<"\n";
                ans+=wt;
            }
        }
        return ans;
    }
};