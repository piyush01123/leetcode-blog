#define ll long long
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> numSet;
        unordered_set<ll> verifier;
        int res=0;
        for (int n: nums)
        {
            if (numSet.count(n-k))
            {
                if (!verifier.count((ll)(n+n-k))) res++;
                verifier.insert(n+n-k);
            }
            if (numSet.count(n+k))
            {
                if (!verifier.count((ll)(n+n+k))) res++;
                verifier.insert(n+n+k);
            }
            numSet.insert(n);
        }
        return res;
    }
};