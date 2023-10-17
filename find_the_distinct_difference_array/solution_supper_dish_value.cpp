class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> pref, suff;
        vector<int> distPref(n), distSuff(n), res(n);
        for(int i=0;i<n;i++){pref.insert(nums[i]); distPref[i]=pref.size();}
        for(int i=n-1;i>=0;i--){suff.insert(nums[i]); distSuff[i]=suff.size();}
        for(int i=0;i<n-1;i++) res[i] = distPref[i]-distSuff[i+1];
        res[n-1] = distPref[n-1];
        return res;
    }
};