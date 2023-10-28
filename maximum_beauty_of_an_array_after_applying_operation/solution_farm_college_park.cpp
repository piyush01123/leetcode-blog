class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int pos = upper_bound(nums.begin(),nums.end(),nums[i]+2*k) - nums.begin();
            res = max(res, pos-i);
        }
        return res;
    }
};