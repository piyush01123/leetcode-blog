We use a HashMap based standard two sum approach.
```
class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        unordered_map<int,int> comps;
        int ctr=0;
        for (int n: nums)
        {
            if (comps.count(n) && comps[n]>0)
            {
                ctr++;
                comps[n]--;
            } else comps[target-n]++;
        }
        return ctr;
    }
};
```

```
TC: O(n)
SC: O(n)
```