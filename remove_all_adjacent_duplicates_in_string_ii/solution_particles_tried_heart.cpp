class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> stk;
        for (char ch: s)
        {
            if (stk.empty() || stk.top().first!=ch)
                stk.push({ch,1});
            else
            {
                stk.top().second++;
                if (stk.top().second==k) stk.pop();
            }
        }
        string res;
        while (!stk.empty())
        {
            res += string(stk.top().second,stk.top().first);
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};