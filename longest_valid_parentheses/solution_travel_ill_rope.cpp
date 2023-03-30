class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n=s.length(), res=0;
        stack<int> stk;
        stk.push(-1);
        for (int i=0; i<n; i++)
        {
            if (s[i]=='(') stk.push(i);
            else
            {
                stk.pop();
                if (stk.empty())
                    stk.push(i);
                else
                    res = max(res, i-stk.top());
            }
        }
        return res;
    }
};