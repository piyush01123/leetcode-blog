class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comps;
        for (int i=0; i<nums.size(); i++){
            cout << nums[i] << endl;
            if (comps.find(nums[i]) != comps.end()){
                //create vector to be returned
                vector<int> g1;
                g1.push_back(comps[nums[i]]);
                g1.push_back(i);
                return g1;
            }
            comps[target-nums[i]] = i;
        }
    }
};