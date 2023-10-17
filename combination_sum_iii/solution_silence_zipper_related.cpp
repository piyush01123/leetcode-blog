class Solution {
public:
    void dfs(int curr, int target, int count,  vector<vector<int>> &res, vector<int> &v)
    {
        if (count==0 && target==0){res.push_back(v);return;}
        if (count<0 || target<0 || curr>=10) return;
        v.push_back(curr);
        dfs(curr+1, target-curr, count-1, res, v);
        v.pop_back();
        dfs(curr+1, target, count, res, v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int>v;
        dfs(1,n,k,res,v);
        return res;
    }
};