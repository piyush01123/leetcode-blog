class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>> stk;
        for (char ch: s)
        {
            if (!stk.empty() && stk.top().first==ch && stk.top().second==k-1)
                stk.pop();
            else
            {
                if (stk.empty() || stk.top().first!=ch) stk.push({ch,1});
                else
                {
                    // stk.top().first==ch
                    int curr = stk.top().second;
                    stk.pop();
                    stk.push({ch,curr+1});
                }
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