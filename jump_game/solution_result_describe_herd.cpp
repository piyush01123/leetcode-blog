class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size(), cur=0, reach=0;
        while(cur<=reach)
        {
            reach = max(reach, cur+nums[cur]);
            cur++;
            if (reach>=n-1) break;
        }
        return (reach>=n-1);
    }
};