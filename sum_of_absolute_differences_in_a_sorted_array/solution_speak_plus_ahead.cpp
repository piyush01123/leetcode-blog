class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n = nums.size(), cur=0;
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<int> cumsum, res;
        for(int i=0; i<n; i++) cumsum.push_back(cur+=nums[i]);
        for(int i=0; i<n; i++) res.push_back(total - 2*cumsum[i] + (-n+2+2*i)*nums[i]);
        return res;
    }
};