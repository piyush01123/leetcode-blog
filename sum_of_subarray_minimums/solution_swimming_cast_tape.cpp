class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int len = arr.size();
        long sum = 0;
        stack<int> stack;
        int j, k;

        for (int i = 0; i <= len; i++) {
            while (!stack.empty() && arr[stack.top()] > (i == len ? INT_MIN : arr[i])) {
                j = stack.top();
                stack.pop();
                k = stack.empty() ? -1 : stack.top();
                sum += (long)arr[j] * (i - j) * (j - k);
            }
            stack.push(i);
        }
        return (int)(sum % (long) (1e9 + 7));        
    }
};