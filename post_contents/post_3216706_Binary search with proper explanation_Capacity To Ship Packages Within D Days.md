# Intuition\r
<!-- Describe your first thoughts on how to solve this problem. -->\r
We need to find the minimum possible capacity that will work. So, we can think of the problem as a search problem with a test of whether it will work at a given capacity. If we want to find the answer in a range `[0,M]` then we can apply the test at `M/2` and if it works then we recurse in the lower half and if it does not work then we recurse in the upper half. In this way we can come up with a binary search.\r
\r
# Approach\r
<!-- Describe your approach to solving the problem. -->\r
To create the test described above we need to write a function `bool possible(int capacity, int days, vector<int>&weights)` which will return `true` if it is possible and `false` if it is not possible to work with `capacity`. We will use this for binary search as described previously.\r
\r
\r
# Code\r
```\r
class Solution {\r
public:\r
    bool possible(int capacity, int days, vector<int>&weights)\r
    {\r
        int n=weights.size(), i=0, ctr=0;\r
        while(i<n)\r
        {\r
            if (weights[i]>capacity) return false;\r
            int cur = 0;\r
            while(i<n && cur+weights[i]<=capacity)\r
            {\r
                cur += weights[i];\r
                i++;\r
            }\r
            ctr ++;\r
        }\r
        return (ctr<=days);\r
    }\r
    int shipWithinDays(vector<int>& weights, int days) \r
    {\r
        int lo=0, hi=INT_MAX;\r
        while (lo<=hi)\r
        {\r
            int mid = lo + (hi-lo)/2;\r
            if (possible(mid, days, weights)) hi = mid-1;\r
            else lo = mid+1;\r
        }\r
        return lo;\r
    }\r
};\r
```\r
\r
# Complexity\r
- Time complexity: $O(n \log(M))$ where $M$ is the maximum possible value of `capacity`. It can be the maximum value of `weights` array but in our implementation we have taken it to be `INT_MAX` since the difference is trivial anyway (in log scale).\r
<!-- Add your time complexity here, e.g. $$O(n)$$ -->\r
\r
- Space complexity: $O(1)$\r
<!-- Add your space complexity here, e.g. $$O(n)$$ -->\r
