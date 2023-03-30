class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int n: nums)
        {
            if (sub.size()==0 || n > sub[sub.size()-1])
                sub.push_back(n);
            else
            {
                vector<int>::iterator it = lower_bound(sub.begin(),sub.end(),n);
                *it = n;
            }
        }
        return sub.size();
    }
};