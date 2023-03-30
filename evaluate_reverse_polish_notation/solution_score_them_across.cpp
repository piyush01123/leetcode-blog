#define ll long long
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<ll> stk;
        for (string token: tokens)
        {
            if (isdigit(token.back()))
            {
                stk.push((ll)stoi(token)); 
                continue;
            }
            ll a = stk.top(); stk.pop();
            ll b = stk.top(); stk.pop();
            if (token=="+") stk.push(b+a);
            if (token=="-") stk.push(b-a);
            if (token=="*") stk.push(b*a);
            if (token=="/") stk.push(b/a);
        }
        return (int)stk.top();
    }
};