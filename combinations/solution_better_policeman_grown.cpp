class Solution {
public:
    void util(vector<int>&vec, vector<vector<int>>&res, int n, int k, int cur)
    {
        if (vec.size()==k){res.push_back(vec); return;}
        if (cur>n) return;
        vec.push_back(cur);
        util(vec, res, n, k, cur+1);
        vec.pop_back();
        util(vec, res, n, k, cur+1);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> vec;
        util(vec,res,n,k,1);
        return res;
    }
};