class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending_here=nums[0], max_so_far=nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            max_ending_here = max(max_ending_here,0)+nums[i];
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};