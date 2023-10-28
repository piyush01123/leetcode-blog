class Solution {
public:
    int minimizedStringLength(string s) 
    {
        unordered_set<char> chars;
        for(char ch: s) chars.insert(ch);
        return chars.size();
    }
};