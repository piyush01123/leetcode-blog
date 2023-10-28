class Solution {
    int mod=1e9+7;
public:
    int sumDistance(vector<int>& nums, string s, int d) 
    {
        int n = nums.size();
        long long res = 0;
        unordered_map<char,int> dirs {{'L',-1}, {'R',1}};
        for (int i=0; i<n; i++) nums[i] += dirs[s[i]] * d;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++) 
        {
            res += (long long)nums[i] * (2*i+1-n);
            res %= mod;
        }
        return res;
    }
};

/*
[a,b,c,d,e]
(4-0)e + (3-1)d + (2-2)c + (1-3)b + (0-4)a
3e+2d+0c-2b-4a
*/