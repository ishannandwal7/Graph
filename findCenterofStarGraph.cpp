class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        int n=edges.size();
        for(auto x:edges){
            mp[x[0]]++;
            mp[x[1]]++;
            if(mp[x[0]]==n){return x[0];}
            if(mp[x[1]]==n){return x[1];}
        }
        return -1;
        
    }
};