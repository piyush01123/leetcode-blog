class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_ending_here=nums[0], max_so_far=nums[0], n=nums.size();
        for (int i=1; i<n; i++)
        {
            max_ending_here = max(max_ending_here,0)+nums[i];
            max_so_far = max(max_so_far, max_ending_here);
        }
        vector<int>rightSums(n,0),maxRight(n,0);
        rightSums[n-1]=nums[n-1]; maxRight[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) rightSums[i]=rightSums[i+1]+nums[i];
        for(int i=n-2;i>=0;i--) maxRight[i]=max(maxRight[i+1],rightSums[i]);
        int res = max_so_far, leftSum=0;
        for(int i=0;i<n-2;i++)
        {
            leftSum+=nums[i];
            res = max(res, leftSum+maxRight[i+2]);
        }
        return res;
    }
};