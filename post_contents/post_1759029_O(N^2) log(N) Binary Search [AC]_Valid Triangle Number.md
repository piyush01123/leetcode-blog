Firstly sort `nums`.
Now chose 1st two sides of triangle in for loop. 
Say `a=nums[i], b=nums[j]` where `i<j`. 
For the 3rd side of the triangle, check the lowest index where `a+b` or any number greater than that occurs in case `a+b` is absent. Call this index as `k`.
Then, valid triangles can be with chosen `a`, `b` and  `c` can be chosen from index between indices `j` and `k`.


```
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), res=0;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                auto it = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]);
                int pos = it-nums.begin();
                if (pos-j-1>0) res+=(pos-j-1);
            }
        }
        return res;
    }
};
```