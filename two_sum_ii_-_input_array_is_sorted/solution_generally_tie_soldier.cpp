class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> comps;
        for (int i=0; i<numbers.size(); i++)
        {
            if (comps.count(numbers[i])) return {comps[numbers[i]]+1,i+1};
            comps[target-numbers[i]] = i;
        }
        return {};
    }
};