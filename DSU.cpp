class DSU{
public:
    int nodes;
    vector<int>rank,parent,size;
    DSU(int nodes){
        this->nodes = nodes;
        rank.resize(nodes+1);
        parent.resize(nodes+1);
        size.resize(nodes+1,1);
        for(int i=1;i<=nodes;++i){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findParent(int node){
        // while(parent[node]!=node){
        //     node=parent[node];
        // }
        // return node;

        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    } 

    void makeUnion(int u,int v){
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        int rankU = rank[u];
        int rankV = rank[v];
        if(ultimateParentU == ultimateParentV){return ;}
        if(rankU==rankV){
            parent[v]=ultimateParentU;
            rank[u]++;
        }else{
            if(rankV<rankU){
                parent[v]=ultimateParentU;
            }else{
                parent[u]=ultimateParentV;
            }
        }
    }

    void unionBySize(int u,int v){
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);
        if(ultimateParentU == ultimateParentV){return ;}
        if(size[u]<size[v]){
            parent[u]=ultimateParentV;
            size[v]+=size[u];
        }
        else{
            if(size[u]==size[v]){
                parent[u]=ultimateParentV;
                size[v]+=size[v];
            }
            else{
                parent[v]=ultimateParentU;
                size[u]+=size[v];
            }
        }

    }
};

int main(){
    DSU dsu(7);
    dsu.unionBySize(1,2);
    dsu.unionBySize(2,3);
    dsu.unionBySize(4,5);
    dsu.unionBySize(6,7);
    dsu.unionBySize(5,6);

    cout<<dsu.findParent(3)<<" "<<dsu.findParent(7);
    dsu.unionBySize(3,7);

 cout<<dsu.findParent(3)<<" "<<dsu.findParent(7);
    
    return 0;
}