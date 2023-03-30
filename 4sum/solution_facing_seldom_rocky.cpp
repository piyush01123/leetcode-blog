#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return KSum(nums, target, 4, 0);
    }
    vector<vector<int>> KSum(vector<int>&nums, ll target, \
                             int K, int start)
    {
        if (start>=nums.size()) return {};
        if (target<(ll)nums[start]*K || target>(ll)nums.back()*K) return {};
        if (K==2) return twoSum(nums, target, start);
        set<vector<int>> res;
        for (int i=start; i<nums.size(); i++)
        {
            vector<vector<int>> kSumPrev = KSum(nums, target-nums[i], K-1, i+1);
            for (auto subset: kSumPrev)
            {
                subset.push_back(nums[i]);
                res.insert(subset);
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
    vector<vector<int>> twoSum(vector<int>&nums, ll target, int start)
    {
        vector<vector<int>> res;
        int lo=start, hi=nums.size()-1;
        while(lo<hi)
        {
            ll cur = (ll)nums[lo] + nums[hi];
            if (cur==target)
            {
                res.push_back({nums[lo],nums[hi]});
                lo++;
                hi--;
            }
            else if (cur<target) lo++;
            else hi--;
        }
        return res;
    }
};