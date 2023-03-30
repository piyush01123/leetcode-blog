class Solution {
public:
    int calculate(string s) 
    {
        stack<int> stk;
        int n=s.length(), res=0, tmp=0;
        char sign = '+';
        for (int i=0; i<n; ++i)
        {
            if (isdigit(s[i]))
                tmp = 10*tmp + (s[i]-'0');
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == s.size()-1) 
            {
            if (sign=='+')
                    stk.push(tmp);
                if (sign=='-')
                    stk.push(-tmp);
                if (sign=='*'||sign=='/')
                {
                    int curr = (sign=='*') ? (stk.top()*tmp) : (stk.top()/tmp);
                    stk.pop();
                    stk.push(curr);
                }
                sign = s[i];
                tmp = 0;
            }
        }
        while (!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};