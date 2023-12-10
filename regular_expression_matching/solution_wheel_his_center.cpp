class Solution {
    vector<vector<int>> dp;
public:
    bool isMatch(string s, string p) 
    {
        int slen=s.length(), plen=p.length();
        if (plen==0) return (slen==0);
        if (dp.size()==0) dp = vector<vector<int>>(slen+1, vector<int>(plen+1,2));
        if (dp[slen][plen]!=2) return dp[slen][plen];
        bool fm = (slen>0) && (s[0]==p[0] || p[0]=='.');
        if (plen>=2 && p[1]=='*') 
            return dp[slen][plen] = (fm && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
        else
            return dp[slen][plen] = fm && isMatch(s.substr(1), p.substr(1));
    }
};