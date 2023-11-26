class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_set<string> dictSet = unordered_set<string>(dictionary.begin(),dictionary.end());
        vector<int> dp(s.length()+1,0);
        for(int index=s.length()-1; index>=0; index--)
        {
            dp[index] = 1 + dp[index+1];
            for (int len=1; len<=s.length()-index; len++)
                if (dictSet.count(s.substr(index,len)))
                    dp[index] = min(dp[index], dp[index+len]);
        }
        return dp[0];
    }
};