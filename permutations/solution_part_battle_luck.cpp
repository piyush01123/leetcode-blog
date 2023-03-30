class Solution {
public:
    void util(vector<int>nums, vector<vector<int>> &res, vector<int> &curr)
    {
        if (curr.size()==nums.size()) 
        {
            res.push_back(curr);
            return;
        }
        for (int i=0; i<nums.size(); i++)
        {
            if (find(curr.begin(),curr.end(),nums[i])!=curr.end()) continue;
            curr.push_back(nums[i]);
            util(nums, res, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        util(nums, res, curr);
        return res;
    }
};