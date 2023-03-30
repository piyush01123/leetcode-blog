class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> comps;
        int palindrome_size = 0;
        for (string word: words)
        {
            if (comps.find(word)!=comps.end()&&comps[word])
            {
                comps[word]-=1;
                palindrome_size += 4;
            }
            else comps[string(word.rbegin(), word.rend())]+=1;
        }
        for (auto pair: comps)
        {
             string word=pair.first;
             if (comps[word] && word[0]==word[1]) {palindrome_size += 2; break;}
           
        }
        return palindrome_size;
    }
};