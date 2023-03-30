class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> S;
        for (int n: nums) S.insert(n);
        int res = 0;
        for (int n: nums)
        {
            if (S.count(n-1)) continue;
            int curr = n, count=0;
            while (S.count(curr++)) count++;
            res = max(res,count);
        }
        return res;
    }
};