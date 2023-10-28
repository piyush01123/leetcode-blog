class Solution {
    int mod=1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        int n=nums.size(), res=0, j=n-1;
        vector<int>powers(n);
        powers[0]=1;
        for(int i=1; i<n; i++) powers[i] = (2*powers[i-1])%mod;
        sort(nums.begin(),nums.end());
        for (int i=0; i<n; i++)
        {
            if (2*nums[i]>target) break;
            int cur = target-nums[i];
            while (nums[j]>cur) j--;
            res += powers[j-i];
            res %= mod;
        }
        return res;
    }
};