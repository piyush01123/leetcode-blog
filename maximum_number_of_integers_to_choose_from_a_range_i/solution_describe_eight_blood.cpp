class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        unordered_set<int>bannedSet(banned.begin(),banned.end());
        int curSum = 0, ctr=0, cur;
        for (cur=1; cur<=n; cur++)
        {
            if (bannedSet.count(cur)) continue;
            curSum += cur;
            if (curSum > maxSum) break;
            ctr++;
        }
        return ctr;
    }
};