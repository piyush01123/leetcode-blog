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
We just repeat Word Break for each word with all the other words.

# Complexity
- Time complexity: $O(N*M^3)$ where N is size of `words` array and `M` is the length of longest word. $N*M^2$ can be seen clearly from the `for` loops in code below. Extra `M` term is for string hashing.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(N*M)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_set<string> wordSet(words.begin(),words.end());
        vector<string> res;
        for (string word: words)
        {
            wordSet.erase(word);
            int n = word.length();
            vector<bool> valid(n+1, false);
            valid[0] = true;
            for (int j=1; j<=n; j++)
                for (int i=0; i<j && !valid[j]; i++)
                    valid[j] = valid[i] && wordSet.count(word.substr(i,j-i));
            if (valid[n]) res.push_back(word);
            wordSet.insert(word);
        }
        return res;        
    }
};
```