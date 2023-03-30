class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> S;
        int n = nums.size();
        int i = 1;
        while (i<n)
        {
            if (S.count(nums[i-1]+nums[i])) return true;
            S.insert(nums[i-1]+nums[i]);
            i++;
        }
        return false;
    }
};