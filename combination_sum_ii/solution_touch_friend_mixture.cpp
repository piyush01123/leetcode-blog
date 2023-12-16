class Solution {
public:
    void dfs(int t, int idx, vector<vector<int>>&res, vector<int>&r, vector<int>&nums)
    {
        if (t==0){res.push_back(r); return;}
        if (t<0 || idx==nums.size()) return;
        r.push_back(nums[idx]);
        dfs(t-nums[idx], idx+1, res, r, nums);
        r.pop_back();
        idx++;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        dfs(t, idx, res, r, nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        for(int k: candidates) cout<<k<<','; cout<<endl;
        vector<vector<int>>res;
        vector<int>r;
        dfs(target, 0, res, r, candidates);
        return res;
        return vector<vector<int>>(res.begin(),res.end());
    }
};