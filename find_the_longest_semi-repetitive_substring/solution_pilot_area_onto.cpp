class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) 
    {
        int n = s.length();
        vector<int> violations;
        for(int i=1; i<n; i++) if(s[i]==s[i-1]) violations.push_back(i);
        if (violations.size()<2) return n;
        int res = violations[1];
        for (int i=2; i<violations.size(); i++) res = max(res, violations[i]-violations[i-2]);
        res = max(res, n-violations[violations.size()-2]);
        return res;
        
    }
};