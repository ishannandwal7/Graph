int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int lo=0,hi=n-1;
	while(lo<=hi){
		int mid=lo+hi;
		mid/=2;
		if(arr[mid]<x){
			lo=mid+1;
		}else{
			// ans=mid;
			hi=mid-1;
		}
	}
	return lo;
}