class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        if (n<3) return false;

        stack<int> stk;
        int cand_mid = INT_MIN;
        
        for (int i=n-1; i>=0; i--)
        {
            if (nums[i]<cand_mid) return true;
            while(stk.size()>0 && nums[i]>stk.top())
            {
                cand_mid = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};