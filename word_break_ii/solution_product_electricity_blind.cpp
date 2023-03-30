class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& words) 
    {
        unordered_set<string> wordSet(words.begin(),words.end());
        int n = s.length();
        vector<vector<string>> A(n+1,vector<string>{});
        A[0] = {"*"};
        for (int j=1; j<=n; j++)
            for (int i=0; i<j; i++)
                if (A[i].size()>0 && wordSet.count(s.substr(i,j-i)))
                    for (string w: A[i])
                        A[j].push_back(w+" "+s.substr(i,j-i));
        auto res = A[n];
        for (string &s: res) s = s.substr(2);
        return res;
    }
};