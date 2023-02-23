# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Intuition is from [Word Break](https://leetcode.com/problems/word-break). Basically we check at each position, if there is a valid word from any previous position. Reproducing my solution for Word Break below:
```
bool wordBreak(string s, vector<string>& words) 
{
    unordered_set<string> wordSet(words.begin(),words.end());
    int n = s.length();
    vector<bool> valid(n+1, false);
    valid[0] = true;
    for (int j=1; j<=n; j++)
        for (int i=0; i<j && !valid[j]; i++)
            valid[j] = valid[i] && wordSet.count(s.substr(i,j-i));
    return valid[n];
}
```

# Approach
<!-- Describe your approach to solving the problem. -->
Instead of a 1-D boolean `valid` array, here we will maintain a 2-D string array `A`. `A[i]` will have all valid "sentences" for `s[0:i]`. `A[0]` is a single word sentence (placeholder *). To find `A[j]` we look for all previous `A[i]` for all `i` in `0<=i<j` and if we find any sentence in `A[i]` then `A[j]` will have that sentence added with the word `s.substr(i,j-i)`. Finally we get rid of the placeholder and first space character in each sentence of `A[n]` to get the answer.



# Code
```
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
```

Related:
https://leetcode.com/problems/concatenated-words/solutions/3106355/