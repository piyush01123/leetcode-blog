class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> subseq;
        for (int n: nums)
        {
            if (subseq.size()==0 || n>subseq.back())
                subseq.push_back(n);
            else
            {
                vector<int>::iterator it = lower_bound(subseq.begin(),subseq.end(),n);
                *it = n;
            }
        }
        return subseq.size();
    }
};