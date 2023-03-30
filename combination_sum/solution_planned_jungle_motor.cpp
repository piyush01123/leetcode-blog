class Solution {
public:
    void dfs(vector<int>&candidates, int target, vector<vector<int>>&res, vector<int>&r, int idx)
    {
        if (target==0)
        {
            res.push_back(r);
            return;
        }
        while (idx<candidates.size() && target>=candidates[idx])
        {
            r.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], res, r, idx);
            idx++;
            r.pop_back();
        }
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