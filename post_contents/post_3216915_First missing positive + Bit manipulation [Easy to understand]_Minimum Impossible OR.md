# Intuition
This problem seems similar to [First Missing Positive](https://leetcode.com/problems/first-missing-positive/). Here is a solution to that probelm:

```
int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(),nums.end());
    int i = 1;
    while (i <= nums.size()){
        if (!numSet.count(i)) return i;
        i++;
    }
    return i;
}
```
# Observation
Our solution is similar to the above in spirit. The crucial thing to notice is that if we have just powers of 2, we can construct all numbers upto the next power of 2 by their OR.

For example, given the array `[1,2,4,8,16]`, we can do `OR` between various elements to construct all numbers from 1 to 31. So the presence of other numbers in the middle like 3,5,6 etc. does not change the range of possible numbers. Hence these are the only ones that need to be checked.

# Code
```
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) 
    {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int cur = 1;
        while (cur<INT_MAX)
        {
            if (!numSet.count(cur)) return cur;
            cur <<= 1;
        }
        return INT_MAX;
    }
};
```