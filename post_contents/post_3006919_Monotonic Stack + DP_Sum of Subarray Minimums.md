# Intuition + Approach
<!-- Describe your first thoughts on how to solve this problem. -->
The intuition is that while traversing, we will maintain a 1-D DP array such that
```
dp[i] = f(0,i) + f(1,i) + f(2,i) + ... + f(i,i)
```
where 
```
f(j,i) = Minimum from indices j to i (inclusive)
```

Once we are done, we can add the `dp` array to get our answer.

## Example
```
arr = [8,6,3,5,4,9,2]
```
For this example, we want that after we are done, the DP should look like:
```
dp = [8,12,9,14,17,26,14]
```
We can see that how this matches our expectation:
```
dp[0] = 8
dp[1] = 6+6
dp[2] = 3+3+3
dp[3] = 3+3+3+5
dp[4] = 3+3+3+4+4
dp[5] = 3+3+3+4+4+9
dp[6] = 2+2+2+2+2+2+2
```
As expected we can sum the `dp` array to get our answer 100.

## How to create this DP array
We will use a monotonic stack (MS) for this. The basic setting for a MS is:
```
stack<int> stk;
for (int i=0; i<n; i++)
{
    while (!stk).empty() && stk.top()>=A[i]) stk.pop();
    stk.push(A[i]);
}
```
Here we will store the indices instead of the values. For each iteration in `i`, once we are done withe the popping, we can create `dp[i]` as follows:
- If the stack is empty, it means the current element is the smallest of all elements in `(0,i)` range. Hence, `dp[i] = A[i]*(i+1)` corresponding to ranges `(0,i)`, `(1,i)`, `(2,i)`, ...., `(i,i)`.

- If the stack is not empty and the top of the stack is `j`, then, for the ranges `(0,i)`, `(1,i)`, `(2,i)`, ..., `(j,i)`, the minimum element is stored in `dp[j]` (their sum) and for the ranges `(j+1,i)`, `(j+2,i)`, ..., `(i,i)`, the minimum element is `A[i]`. Hence, `dp[i] = dp[j] + A[i]*(i-j)`

# Complexity
- Time complexity: $O(n)$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(n)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
#define ll long long int
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size(), mod=1000000007;
        ll res = 0;
        vector<ll> dp(n,-1);
        stack<int> stk;
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && arr[i]<=arr[stk.top()]) stk.pop();
            if (!stk.empty())
            {
                int j = stk.top();
                dp[i] = dp[j] + arr[i]*(i-j);
            } 
            else dp[i] = arr[i]*(i+1);
            stk.push(i);
        }
        for (int x: dp) res+=x;
        return (int)(res%mod);
    }
};
```