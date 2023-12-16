class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target=0) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> res_set;
        for (int i=0; i<=nums.size()-3; i++)
        {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int lo=i+1, hi=nums.size()-1;
            while(lo<hi)
            {
                int cur = nums[i]+nums[lo]+nums[hi];
                if (cur==target) res_set.insert({nums[i],nums[lo++],nums[hi--]});
                else if (cur<target) lo++;
                else if (cur>target) hi--;
            }
        }
        vector<vector<int>> res;
        for(auto &item: res_set) res.push_back(item);
        return res;
    }
};