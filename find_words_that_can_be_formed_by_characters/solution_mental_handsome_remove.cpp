class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int res = 0;
        unordered_map<char,int> freq;
        for(char ch: chars) freq[ch]++;
        for (string word: words)
        {
            unordered_map<char,int> freqWord;
            bool flag = true;
            for(char ch: word)
            {
                if (!freq.count(ch)) {flag = false; break;}
                if(++freqWord[ch] > freq[ch]) {flag = false; break;}
            }
            if (flag) res += word.size();
        }
        return res;
    }
};