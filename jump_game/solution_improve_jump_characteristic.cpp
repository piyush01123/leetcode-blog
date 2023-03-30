class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minPos = nums.size()-1;
        for (int i=minPos; i>=0; i--)
            if (i+nums[i]>=minPos) minPos = i;
        return minPos<=0;
    }
};