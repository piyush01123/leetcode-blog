class Solution {
    int mod = 1e9+7;
public:
    int dfs(string &s, int k, int i, vector<int>&memo)
    {
        if (i==s.length()) return 1;
        if (memo[i]!=-1) return memo[i];
        if (s[i]=='0') return 0;
        int j = i, res=0;
        string cur = "";
        while(j<s.length())
        {
            cur.push_back(s[j]);
            if (cur.length()>=11 || ((cur.length()==10 && s[i]>'1')) || stoi(cur)>k) break;
            res += dfs(s, k, ++j, memo)%mod;
            res %=mod;
        }
        return memo[i] = res;
    }
    int numberOfArrays(string s, int k) 
    {
        if (k==1) return 0;
        vector<int> memo(s.length(),-1);
        return dfs(s, k, 0, memo);
    }
};