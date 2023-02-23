Notice that to verify if an array element is minimum or not, it is sufficient to verify that it is smaller than both its neighbors (with rotation).ie
```
prev = (mid==0) ? n-1 : mid-1
next = (mid==n-1) ? 0 : mid+1
A[mid]<=A[prev] and A[mid]<=A[next]
```
We want to find an index `mid` in the range `[0,n)` that satisfies this condition. We use binary search for this.

```
int findMin(vector<int>& nums) 
{
	int n=nums.size(), lo=0, hi=n-1, mid;
	while (lo<=hi)
	{
		mid = lo + (hi-lo)/2;
		int prev = (mid-1+n)%n, next = (mid+1)%n;
		if (nums[mid]<=nums[prev] && nums[mid]<=nums[next])
			break;
		else if (nums[mid] <= nums[hi])
			hi = mid-1;
		else
			lo = mid+1; // nums[0...mid] subarray is sorted
	}
	return nums[mid];
}
```