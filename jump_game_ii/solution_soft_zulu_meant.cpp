class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n=nums.size(), ctr=0, reach=0, curEnd=0;
        for(int i=0; i<n-1; i++)
        {
            reach = max(reach, i+nums[i]);
            if (i==curEnd)
            {
                curEnd = reach;
                ctr++;
            }
        }
        return ctr;
    }
};