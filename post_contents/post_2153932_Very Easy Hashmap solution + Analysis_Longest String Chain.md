# Algorithm:
- Sort words by word length in ascending order
- Initialize Hashmap H of type `string->int`
- For each word find subwords (word-1 char) and check if subword is in H. Find the maximum possible value of `H[subword]`  out of all subwords. Call it `ctr`. If there is no subword in H then `ctr=0`
- `H[word] = ctr+1`
- Finally answer is the maximum of all values in `H`.

```
bool complen(string s1, string s2)
{
    return s1.length() < s2.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> H;
        int res=0;
        sort(words.begin(), words.end(), complen);
        for (string word: words)
        {
            int wn = word.length(), ctr=0;
            for (int i=0; i<wn; i++)
            {
                string sub = string(word.begin(),word.begin()+i) + 
                             string(word.begin()+i+1, word.end());
                if (H.count(sub)) ctr=max(ctr,H[sub]);
            }
            H[word]=ctr+1;
            res = max(res, H[word]);
        }
        return res;
    }
};
```
```
TC: O(N*|S| + N*log(N))
SC: O(N)
```
where `N=#(words)`, `|S|=max length of word`

Reasoning for TC:
`N*|S|` term comes because for each word we are finding all the subwords
`N*log(N)` term comes because we are doing a sorting operation in the beginning

Reasoning for SC:
Size of HashMap is N.

PLEASE UPVOTE.