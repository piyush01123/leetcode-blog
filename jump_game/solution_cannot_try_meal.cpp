class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int cur=0, reach=nums[0];
        while (1)
        {
            while(cur<=reach)
            {
                reach = max(reach, cur+nums[cur]);
                if (reach>=n-1) break;
                cur++;
            }
            if (reach>=n-1 || nums[reach]==0) break;
        }
        return (reach>=n-1);
    }
};