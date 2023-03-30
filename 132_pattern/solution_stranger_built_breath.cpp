class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return false;
        stack<int> rightNums;
        int largestSmaller = INT_MIN;
        for (int i=n-1; i>=0; i--)
        {
            if (nums[i]<largestSmaller) return true;
            else
            {
                while (rightNums.size()>0 && nums[i]>rightNums.top())
                {
                    largestSmaller = rightNums.top();
                    rightNums.pop();
                }
            }
            rightNums.push(nums[i]);
        }
        return false;
    }
};