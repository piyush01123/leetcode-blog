class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target=0) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,vector<pair<int,int>>>H;
        for (int i=0; i<n-2; i++)
        {
            int lo=i+1, hi=n-1;
            while (lo<hi)
            {
                if (nums[i]+nums[lo]+nums[hi]==target) 
                {
                    bool ok = true;
                    for (auto p: H[nums[i]])
                    {
                        if(nums[lo]==p.first && nums[hi]==p.second)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) 
                        H[nums[i]].push_back({nums[lo],nums[hi]}); 
                    lo++;hi--;
                }
                else if (nums[i]+nums[lo]+nums[hi]<target) lo++;
                else hi--;
            }
        }
        vector<vector<int>>res;
        for (auto kv: H)
            for (auto p: kv.second)
                res.push_back({kv.first,p.first,p.second});
        return res;
    }
};