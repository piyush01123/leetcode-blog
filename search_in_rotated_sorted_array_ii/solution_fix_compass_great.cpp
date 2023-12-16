class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int num: nums) if(target==num) return true;
        return false;
    }
};