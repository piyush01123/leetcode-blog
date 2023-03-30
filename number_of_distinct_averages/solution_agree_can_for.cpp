class Solution {
public:
    int distinctAverages(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        unordered_set<double> avgs;
        for (int i=0; i<nums.size()/2; i++)
            avgs.insert(double(nums[i]+nums[nums.size()-1-i])/2);
        return avgs.size();
    }
};