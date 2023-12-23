class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) 
    {
        int res = *max_element(nums.begin(),nums.end());
        res*=k;
        res += (k-1)*k/2;
        return res;
    }
};