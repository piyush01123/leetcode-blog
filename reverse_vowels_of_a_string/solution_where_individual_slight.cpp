class Solution {
public:
    string reverseVowels(string s) 
    {
        vector<int> pos,chars;
        unordered_set<char>vowels{'a','e','i','o','u','A','E','I','O','U'};
        for (int i=0; i<s.length(); i++)
        {
            if (vowels.count(s[i]))
            {
                pos.push_back(i);
                chars.push_back(s[i]-'a');
            }
        }
        for (int i=0; i<pos.size(); i++)
            s[pos[i]] = 'a'+chars[pos.size()-1-i];
        return s;
    }
};