class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> vec(1000,0);
        for (auto &pair: nums1) vec[pair[0]-1]+=pair[1];
        for (auto &pair: nums2) vec[pair[0]-1]+=pair[1];
        vector<vector<int>> res;
        for (int i=0; i<1000; i++) if (vec[i]) res.push_back({i+1,vec[i]});
        return res;
    }
};