class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int res=INT_MIN, n=nums.size();
        for(int i=0; 2*i<n; i++) res = max(res, nums[i]+nums[n-1-i]);
        return res; 
    }
};