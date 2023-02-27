Given you have a arithmetic sequence (AS) of length 4 as in the example, you can quickly see that:
- Number of AS of length 3 = (4-3+1)=2
- Number of AS of length 4 = (4-4+1)=1

Hence, Number of AS = 2+1 = 3

You can extend this logic to this:
**Given an AS of maximum length L, `total number of AS=1+2+3+..+L-2 = 1/2*(L-2)*(L-1)`**

So, what we need to do is as we traverse through the array, find out the AS (we keep moving the 2nd pointer till the AS is finished) and then calculate the total number of AS using above formula. 

Now for the fun part:

```
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(), i=0, res=0;
        while (i<n-2)
        {
            int start=i;
            while (i<n-2 && nums[i+1]-nums[i]==nums[i+2]-nums[i+1]) i++;
            int L = i+2-start;
            int num_subs = (L-2)*(L-1)/2;
            res += num_subs;
            i++;
        }
        return res;
    }
};
```