class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n=nums.size(), cur=0, T = accumulate(nums.begin(),nums.end(),0);
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            cur += nums[i];
            res.push_back(T - 2*cur + (-n+2+2*i)*nums[i]);
        }
        return res;
    }
};