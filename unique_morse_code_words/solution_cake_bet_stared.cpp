class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        vector<string>morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uniques;
        for (string word: words)
        {
            string s = "";
            for(char ch: word) s += morse[ch-'a'];
            uniques.insert(s);
        }
        return uniques.size();
    }
};