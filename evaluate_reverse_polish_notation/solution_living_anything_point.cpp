class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> stk;
        for (string s: tokens)
        {
            if (s=="+"||s=="-"||s=="*"||s=="/")
            {
                long a = stk.top();
                stk.pop();
                long b = stk.top();
                stk.pop();
                if (s=="+") stk.push(b+a);
                if (s=="-") stk.push(b-a);
                if (s=="*") stk.push(b*a);
                if (s=="/") stk.push(b/a);
            }
            else
            {
                stk.push((long)stoi(s));
            }
        }
        return stk.top();
    }
};