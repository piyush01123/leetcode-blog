class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0, currEnd=0, jumps=0;
        for (int i=0; i<nums.size()-1; i++)
        {
            reach = max(reach, i+nums[i]);
            if (i==currEnd)
            {
                currEnd = reach;
                jumps++;
            }
        }
        return jumps;
    }
};