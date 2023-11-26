class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        vector<vector<int>>H;
        for(int i=0; i<nums.size(); i++) for(int j=0; j<nums[i].size(); j++)
            if (H.size()==i+j)H.push_back({nums[i][j]});
            else H[i+j].push_back(nums[i][j]);
        vector<int> res;
        for (auto &v:H) for(int i=v.size()-1; i>=0; i--) res.push_back(v[i]);
        return res;
    }
};
