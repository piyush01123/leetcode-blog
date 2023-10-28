class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n = nums.size(); long long curSum=0;
        vector<int> res(n,-1);
        for(int i=0; i<n; i++)
        {
            curSum += nums[i];
            if (i>2*k) curSum -= nums[i-2*k-1];
            if (i>=2*k) res[i-k] = curSum/(2*k+1);
        }
        return res;
    }
};