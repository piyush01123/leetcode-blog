class Solution {
    unordered_set<string> dictSet;
    vector<int> memo;
public:
    int dfs(string s, int index)
    {
        if (index>=s.length()) return 0;
        if (memo[index]!=-1) return memo[index];
        int res = 1 + dfs(s, index+1);
        for (int len=1; len<=s.length()-index;len++)
            if (dictSet.count(s.substr(index,len)))
                    res = min(res, dfs(s, index+len));
        return memo[index] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        dictSet = unordered_set<string>(dictionary.begin(),dictionary.end());
        memo = vector<int>(s.length()+1,-1);
        return dfs(s,0);
    }
};