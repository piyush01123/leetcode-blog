class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res=1, curr=1, n = nums.size();
        for (int i=1; i<n; i++)
        {
            if (nums[i]>nums[i-1]) curr++;
            else
            {
                if (curr>res) res=curr;
                curr=1;
            }
        }
        if (curr>res) res=curr;
        return res;
    }
};