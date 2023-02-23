The question would be very easy if not for the unique triplet thing. All we need to do is sort the array and for each element `A[i]` solve the `2Sum for sorted array` using the two pointer approach in the subarray `{A[i+1]..A[n-1]}`. 
```
vector<vector<int>> threeSum(vector<int>& nums, int target=0) {
	sort(nums.begin(),nums.end());
	int n = nums.size();
	vector<vector<int>>res;
	for (int i=0; i<n-2; i++)
	{
		int lo=i+1, hi=n-1;
		while (lo<hi)
		{
			if (nums[i]+nums[lo]+nums[hi]==target) 
			{
				res.push_back({nums[i],nums[lo],nums[hi]});
				lo++;hi--;
			}
			else if (nums[i]+nums[lo]+nums[hi]<target) lo++;
			else hi--;
		}
	}
	return res;
}
```
However this will give us duplicate triplets. 

To incorporate the unique triplet thing, we use Hashmaps to store results and before inserting a new result check if it exists already. We use the lowest of the triplet as key and the remaining two are inserted as a pair of ints. There is no particular logic for this choice. You could choose another schema as well.
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target=0) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,vector<pair<int,int>>>H;
        for (int i=0; i<n-2; i++)
        {
            int lo=i+1, hi=n-1;
            while (lo<hi)
            {
                if (nums[i]+nums[lo]+nums[hi]==target) 
                {
                    bool ok = true;
                    for (auto p: H[nums[i]])
                    {
                        if(nums[lo]==p.first && nums[hi]==p.second)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) 
                        H[nums[i]].push_back({nums[lo],nums[hi]}); 
                    lo++;hi--;
                }
                else if (nums[i]+nums[lo]+nums[hi]<target) lo++;
                else hi--;
            }
        }
        vector<vector<int>>res;
        for (auto kv: H)
            for (auto p: kv.second)
                res.push_back({kv.first,p.first,p.second});
        return res;
    }
};
```