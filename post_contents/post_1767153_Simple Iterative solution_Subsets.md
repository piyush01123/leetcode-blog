- Start with `curr = [[]]`
- Iterate over `nums`. At each iteration, double the size of subsets.
- To do this just take all current elements of `curr`. Append last seen element `nums[i]` to these arrays and push them back to `curr`.
```
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
```