class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> H;
        for (int i=0; i<nums.size(); i++)
        {
            if (H.count(nums[i])) return {H[nums[i]], i};
            H[target-nums[i]] = i;
        }
        return {};
    }
};