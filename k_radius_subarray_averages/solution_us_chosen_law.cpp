class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(nums.size()<2*k+1) return vector<int>(nums.size(),-1);
        int n = nums.size(); long long int curr = 0;
        vector<int> ones = vector<int>(k,-1);
        vector<int> res = ones;
        for (int i=0;i<=2*k;i++) curr+=nums[i];
        res.push_back(curr/(2*k+1));
        for (int i=k+1;i<n-k;i++){curr+=nums[i+k]-nums[i-k-1];res.push_back(curr/(2*k+1));}
        res.insert(res.end(),ones.begin(),ones.end());
        return res;
    }
};