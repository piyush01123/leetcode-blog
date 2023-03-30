class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_set<int> numset;
        for (int i=0; i<k && i<n; ++i)
        {
            if (numset.count(nums[i])) return true;
            numset.insert(nums[i]);
        }
        for (int i=k; i<n; ++i)
        {
            if (numset.count(nums[i])) return true;
            numset.insert(nums[i]);
            numset.erase(nums[i-k]);
        }
        return false;
    }
};