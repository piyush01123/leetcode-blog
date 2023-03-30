class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> H;
        for (char ch: s)
        {
            if (H.empty() || H.top().first!=ch) H.push({ch,1});
            else
            {
                H.top().second++;
                if (H.top().second==k) H.pop();
            }
        }
        string t="";
        while (!H.empty())
        {
            auto p=H.top(); 
            t+=string(p.second,p.first);
            H.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};