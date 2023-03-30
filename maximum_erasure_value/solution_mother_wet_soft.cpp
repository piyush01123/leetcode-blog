class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(), i=0, j=0, candidate=0, res=0;
        unordered_set<int> S;
        while (i<n && j<n)
        {
            if (!S.count(nums[j]))
            {
                candidate += nums[j];
                S.insert(nums[j++]);
            }
            else 
            {
                candidate -= nums[i];
                S.erase(nums[i++]);
            }
            res = max(res, candidate);
        }
        return res;
    }
};