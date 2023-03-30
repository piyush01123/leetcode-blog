class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> mySet;
        for (int i=0; i< nums.size(); i++){
            mySet.insert(nums[i]);
        }
        int i = 1;
        while (i <= nums.size()){
            if (mySet.find(i) == mySet.end()){
                return i;
            }
            i++;
        }
        return i;
    }
};