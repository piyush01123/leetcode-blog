class Solution {
public:
    void util(vector<int>nums, vector<vector<int>>&res, vector<int>&curr, vector<bool>&used)
    {
        if (curr.size()==nums.size())
        {
            res.push_back(curr);
            return;
        }
        for (int i=0; i<nums.size(); i++)
        {
            if (used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1])) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            util(nums, res, curr, used);
            used[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(),false);
        util(nums, res, curr, used);
        return res;
    }
};