class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        vector<int> freq(26,0);
        for(char ch: chars) freq[ch-'a']++;
        int res=0;
        for(string word: words)
        {
            vector<int> freqWord(26,0);
            for(char ch: word) freqWord[ch-'a']++;
            bool flag = true;
            for(int i=0; i<26; i++) if(freqWord[i]>freq[i]) {flag=false; break;}
            if (flag) res += word.length();
        }
        return res;   
    }
};