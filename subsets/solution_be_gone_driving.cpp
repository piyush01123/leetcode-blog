#define pb push_back
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> curr;
        curr.pb({});
        for (int n: nums)
        {
            int sz=curr.size();
            for (int i=0; i<sz; i++){auto v = curr[i]; v.pb(n); curr.pb(v);}
        }
        return curr;
    }
};