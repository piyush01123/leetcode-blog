class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return subarraysWithAtMostKDistinct(nums,k)-subarraysWithAtMostKDistinct(nums,k-1);
    }
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) 
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