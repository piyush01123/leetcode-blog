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