pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int lo=0,hi=n-1;
        pair<int, int> ans = {-1,-1};
        while(lo<=hi){
		int mid=lo+hi;mid/=2;
		if(a[mid]>x){
			hi=mid-1;
		}
		else{
			ans.first=a[mid];
			lo=mid+1;
		}
	}
	// ans.first=hi;
	lo=0,hi=n-1;
	while(lo<=hi){
		int mid= lo+hi;mid/=2;
		if(a[mid]<x){
			lo=mid+1;
		}else{
			ans.second=a[mid];
			hi=mid-1;
		}
	}
	// ans.second=lo;
	return ans;
}