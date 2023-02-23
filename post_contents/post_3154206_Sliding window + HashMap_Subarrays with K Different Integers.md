We solve the problem of subarray with at most K distinct integers and use it for K and K-1 to get the answer.


```
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
    int atMostK(vector<int>& nums, int k) 
    {
        int n = nums.size(), i=0, res=0;
        unordered_map<int,int> H;
        for (int j=0; j<n; j++)
        {
            H[nums[j]]++;
            while(H.size()>k)
            {
                H[nums[i]]--;
                if (H[nums[i]]==0) H.erase(nums[i]);
                i++;
            }
            res += (j-i+1);
        }
        return res;
    }
};
```