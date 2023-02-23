# Intuition
Consider the example with all words from either `"a"` or `"b"`:
```
ideas = ["apple","and","alpha","amaze","aye","aid","bye","bid","bat","beef","brown"]
```
Based on the starting letter and the suffix we can see this pattern:
```
"a": ["pple","nd","lpha","maze","ye","id"]
"b": ["ye","id","at","eef","rown"]
```
Notice that `"ye"` and `"id"` are present in both. These cannot be used for company names because for example suppose we use `"aye","bat"` we will have `"bye aat"` as the company name but `"bye"` is present in original list of `ideas` hence not valid. So, we need to find the suffixes present in only one of the arrays:
```
"a": ["pple","lpha","nd","maze"]
"b": ["at","eef","rown"]
```
We can choose 12 pairs from here and from them we will have 24 company names:
```
company_names = ["aat bpple", "bpple aat", "aeef bpple", "bpple aeef", "arown bpple", "bpple arown", "aat blpha", "blpha aat", "aeef blpha", "blpha aeef", "arown blpha", "blpha arown", "aat bnd", "bnd aat", "aeef bnd", "bnd aeef", "arown bnd", "bnd arown", "aat bmaze", "bmaze aat", "aeef bmaze", "bmaze aeef", "arown bmaze", "bmaze arown"]
```
Hence answer for this example is 24.

# Approach
We will use 26 HashSets to store suffixes for each alphabet. For each pair of alphabets, we will add their contribution as $2*n1*n2$ where $n1,n2$ are the suffixes from each alphabet not present in the other one.

# Code
```
class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long res = 0;
        vector<unordered_set<string>> ideaSet(26, unordered_set<string>{});
        for(string idea: ideas) ideaSet[idea[0]-"a"].insert(idea.substr(1));
        for (int i=0; i<26; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                int common=0;
                for(string idea: ideaSet[j]) common+=ideaSet[i].count(idea);
                int n1 = ideaSet[i].size()-common, n2=ideaSet[j].size()-common;
                res += 2LL*n1*n2;
            }
        }
        return res;
    }
};
```

# Complexity
Worst case time complexity is $O(nm)$ where $n$ is the number of words in `ideas`, $m$ is the maximum size of word in `ideas` .
Space complexity: $O(nm)$

# Alternative solution
We can have slightly more efficient solution (same TC) if instead of storing suffixes we just maintain a 26x26 frequency table to check validity of name.
```
class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long res = 0;
        unordered_set<string> ideaSet(ideas.begin(),ideas.end());
        vector<vector<int>>freq_table(26,vector<int>(26,0));
        for (string idea: ideas)
        {
            for(char ch="a"; ch<="z"; ch++)
            {
                string namePart = string(1,ch)+idea.substr(1);
                if(!ideaSet.count(namePart))
                    freq_table[idea[0]-"a"][ch-"a"]++;
            }
        }
        for (int i=0; i<26; i++)
            for (int j=i+1; j<26; j++)
                res += 2LL*freq_table[i][j]*freq_table[j][i];
        return res;
    }
};
```