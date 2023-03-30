class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
    int atMostK(vector<int>& nums, int k) 
    {
        int n=nums.size(), ctr=0, res=0, i=0;
        for (int j=0; j<n; j++)
        {
            ctr += (nums[j]&1);
            while (ctr>k)
            {
                ctr-=(nums[i]&1);
                i++;
            }
            res += (j-i+1);
        }
        return res;
    }
};