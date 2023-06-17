class Solution {
    int mod=1e9+7;
public:
    int sumOfPower(vector<int>& nums) {
        int  n=nums.size();
        long long res=0, pre=0;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++)
        {
            res += (((pre+nums[i])%mod * nums[i])%mod * nums[i])%mod;
            pre = (pre<<1)%mod + nums[i];
            pre %= mod;
            res %= mod;
        }
        return res;
    }
};

/*
[a,b,c,d,e]
d2d + d2c + 2d2b + 4d2a
e2e + e2d + 2e2c + 4e2b + 8e2a
*/