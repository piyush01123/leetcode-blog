Fastest O(N log N) solution in C++:
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int n: nums)
        {
            if (sub.size()==0 || n > sub[sub.size()-1])
                sub.push_back(n);
            else
            {
                vector<int>::iterator it = lower_bound(sub.begin(),sub.end(),n);
                *it = n;
            }
        }
        return sub.size();
    }
};
```

O(N^2) solution:
C++:
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++) for(int j=0;j<i;j++) if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1); 
        return *max_element(dp.begin(), dp.end());
    }
};
```
Python:
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1 for _ in range(n)]
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]:
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)
```
Java:
```
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for(int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = Math.max(dp[i], dp[j]+1);
                }
            }
        }
        return Arrays.stream(dp).max().getAsInt();
    }
}
```
JavaScript:
```
var lengthOfLIS = function(nums) {
    var n = nums.length;
    var dp = Array(n);
    dp.fill(1);
    for(let i=0; i<n; i++)
        {
            for (let j=0; j<i; j++)
                {
                    if (nums[i]>nums[j]){
                        dp[i] = Math.max(dp[i],dp[j]+1);
                    }
                }
        }
    return Math.max(...dp);
};
```