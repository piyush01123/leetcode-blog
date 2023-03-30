class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        for (int i=0; i<nums.size(); i++){
            if (complements.find(nums[i]) != complements.end()){
                vector<int> answer;
                answer.push_back(complements[nums[i]]+1);
                answer.push_back(i+1);
                return answer;
            } else {
                complements[target-nums[i]] = i;
            }
        }
        return vector<int>();
    }
};