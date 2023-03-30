class Solution {
    unordered_map<int, vector<int>> H;
public:
    Solution(vector<int>& nums) 
    {
        for (int i=0; i<nums.size(); i++) H[nums[i]].push_back(i);
    }
    
    int pick(int target) 
    {
        vector<int> vec = H[target];
        int res = -1;
        for (int i=1; i<=vec.size(); i++)
            if (rand()%i==i-1) res = vec[i-1];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */