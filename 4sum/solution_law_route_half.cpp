#define ll long long

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.size()<4) return {};
        sort(nums.begin(), nums.end());
        // for(int n: nums) cout<<n<<','; cout<<endl;
        return KSum(nums, target, 4, 0);
    }
    vector<vector<int>> KSum(vector<int>&nums, ll target, int K, int start)
    {
        if (target/K<nums[start] || target/K>nums.back()) return {};
        if (K==2) return twoSum(nums, target, start);
        vector<vector<int>> res;
        for (int i=start; i<=nums.size()-K; i++)
        {
            if (i>start && nums[i]==nums[i-1]) continue;
            vector<vector<int>> prev = KSum(nums, target-nums[i], K-1, i+1);
            for (auto &vec: prev)
            {
                vec.insert(vec.begin(), nums[i]);
                res.push_back(vec);
            }
        }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>&nums, ll target, int start)
    {
        // cout<<'T'<<target<<'S'<<start<<endl;
        vector<vector<int>> res;
        int lo=start, hi=nums.size()-1;
        while (lo<hi)
        {
            // cout<<"lo"<<lo<<"hi"<<hi<<endl;
            while (lo<nums.size() && lo>start && nums[lo]==nums[lo-1]) lo++;
            while (hi>0 && hi<nums.size()-1 && nums[hi]==nums[hi+1]) hi--;
            if (lo>=hi) break;
 
            // cout<<"Test "<<"lo"<<lo<<"hi"<<hi<<endl;
            ll cur = nums[lo]+nums[hi];
            if (cur==target) res.push_back({nums[lo++],nums[hi--]});
            else if (cur<target) lo++;
            else if (cur>target) hi--;
        }
        // cout<<"TWOSUM"<<endl;
        // for(auto &v: res){for(int k:v)cout<<k<<','; cout<<endl;}
        // cout<<"/TWOSUM"<<endl;
        return res;       
    }
};