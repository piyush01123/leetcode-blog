class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size(), reach=0, curEnd=0;
        for(int i=0; i<n; i++)
        {
            reach = max(reach, i+nums[i]);
            if(i==curEnd) curEnd = reach;
        }
        return (curEnd>=n-1);
    }
};