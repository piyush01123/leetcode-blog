class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>S(nums.begin(), nums.end());
        while(S.find(original)!=S.end()) original*=2;
        return original;
    }
};