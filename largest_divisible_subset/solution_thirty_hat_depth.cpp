bool cmp(pair<int,int>a, pair<int,int>b)
{
    return a.first<b.first;
}

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> dp(n,{1,-1});
        for (int i=1; i<n; i++)            
            for (int j=0; j<i; j++)
                if (nums[i]%nums[j]==0 && 1+dp[j].first>dp[i].first)
                    dp[i] = {1+dp[j].first,j};
        // for (auto p: dp) cout<<p.first<<','<<p.second<<endl;
        auto it = max_element(dp.begin(),dp.end(),cmp);
        auto p = *it;
        vector<int> res{nums[it-dp.begin()]};
        while(p.second>=0)
        {
            res.push_back(nums[p.second]);
            p = dp[p.second];
        }
        return res;
    }
};