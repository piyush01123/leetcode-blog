class Solution {
public:
    void dfs(vector<int>&nums, int target, vector<vector<int>>&res, vector<int>&cur, int start)
    {
        if (target==0){res.push_back(cur);return;}
        if (target<0 || start==nums.size()) return;
        cur.push_back(nums[start]);
        dfs(nums, target-nums[start], res, cur, start);
        cur.pop_back();
        dfs(nums, target, res, cur, start+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<int> r;
        vector<vector<int>> res;
        dfs(candidates, target, res, r, 0);
        return res;
    }
};