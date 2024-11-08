int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	// return upper_bound(arr.begin(),arr.end(),x)-arr.begin();	
	int lo=0 ,hi=n-1;
	while(lo<=hi){
		int mid=lo+hi;mid/=2;
		if(arr[mid]<=x){
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	return lo;
}