# Intuition
The idea is to maintain a montonically decreasing stack of temperatures. As soon as you see a value greater than the stack top, you have found the answer for the numbers at stack top which have value lower than current value.

# Approach
We will use a monotonically decreasing stack. When we see a value smaller than stack top, just add it to the stack. But if we see a value higher than the stack top then we will update our answer for the stack top and pop from stack. We will keep doing this as long as current value is higher than stack top.

# Complexity
- Time complexity:
O(N) where N is the number of days.
- Space complexity:
O(N) because stack size could go up to the number of days N.

# Code
```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        stack<pair<int,int>> stk;
        vector<int> res(n, 0);
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && temperatures[i]>stk.top().first)
            {
                res[stk.top().second] = i-stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i],i});
        }
        return res;
    }
};
```