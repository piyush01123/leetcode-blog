class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int resP=INT_MAX, resN=INT_MIN, n=nums.size();
        for (int i=0; i<n; i++)
        {
            if (nums[i]>=0) resP=min(resP,nums[i]);
            else resN=max(resN,nums[i]);
        }
        return (resN==INT_MIN || resP<=-resN)?resP:resN;
    }
};