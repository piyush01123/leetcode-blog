class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        long cur=0;
        int n=nums.size(), j=0, res=0;
        for (int i=0; i<n; i++)
        {
            cur += nums[i];
            while((long)(i-j+1)*nums[i] - cur > k) cur -= nums[j++];
            res = max(res, i-j+1);
        }
        return res;
    }
};