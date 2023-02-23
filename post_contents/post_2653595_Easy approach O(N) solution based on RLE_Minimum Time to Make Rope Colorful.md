# Strategy:
Imagine the colors to be written in [RLE](https://en.wikipedia.org/wiki/Run-length_encoding). For eg. "aabaa" is written as `{a(2), b(1), a(2)}`. Then when you see a 1, no need to remove anything but when you see anything other than 1, then we have to remove all but the highest time balloon.

```
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int i=0, res=0; 
        while (i<colors.length())
        {
            int j=i, curSum=0, curMax=INT_MIN;
            while(j<colors.length() && colors[j]==colors[i])
            {
                curSum += neededTime[j];
                curMax = max(curMax, neededTime[j]);
                j++;
            }
            res += (curSum-curMax);
            i = j;
        }
        return res;
    }
};
```

```
TC: O(N)
SC: O(1)
```