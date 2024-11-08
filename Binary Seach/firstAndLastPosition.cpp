pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int>ans ={-1,-1};
    int loInd=lower_bound(arr.begin(),arr.end(),k)-arr.begin();
    int upInd=upper_bound(arr.begin(),arr.end(),k)-arr.begin();
    if(arr[loInd]!=k){return ans;}
    ans={loInd,upInd-1};
    return ans;
}