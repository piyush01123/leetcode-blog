Water trapped at any point is equal to `min(max_to_the_left, max_to_the_right) - h` where `h` is its own height.
So all we need to do is find out that for each point, what is the maximum height to its left and maximum height to its right. This can be achieved in a fairly easy way: Just traverse through the array Left to Right and keep track of the max element seen. Similarly do the same but from Right to Left.
Finally, we do one last traversal to find the total water accumulated but this time from `1 to n-2` because the elements `0` and `n-1` (first and last) cannot hold water.

```
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int curr=0;
        vector<int> maxLtoR(n,0), maxRtoL(n,0);
        for (int i=0; i<n; i++)
        {
            curr = max(curr, height[i]);
            maxLtoR[i] = curr;
        }
        curr = 0;
        for (int i=n-1; i>=0; i--)
        {
            curr = max(curr, height[i]);
            maxRtoL[i] = curr;
        }
        int amt_here, total_amt=0;
        for (int i=1; i<n-1; i++)
        {
            amt_here =  min(maxLtoR[i], maxRtoL[i]) - height[i];
            total_amt += amt_here;
        }
        return total_amt;
    }
};
```

```
TC: O(n)
SC: O(n)
```