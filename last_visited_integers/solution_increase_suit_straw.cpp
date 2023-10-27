class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) 
    {
        vector<int> nums, res;
        int ctr = 0;
        for (string word: words) if (word=="prev")
        {
            ctr++;
            if (nums.size()<ctr) res.push_back(-1);
            else res.push_back(nums[nums.size()-ctr]);
        }
        else {nums.push_back(stoi(word)); ctr=0;}
        return res;
    }
};