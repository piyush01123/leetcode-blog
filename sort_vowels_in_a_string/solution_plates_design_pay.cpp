class Solution {
public:
    string sortVowels(string s) 
    {
        vector<char>vowels;
        auto isVowel = [](char ch){return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';};
        for (char ch: s) if (isVowel(tolower(ch))) vowels.push_back(ch);
        sort(vowels.begin(), vowels.end());
        vector<char>::iterator it = vowels.begin();
        for (int i=0; i<s.length(); i++) if(isVowel(tolower(s[i]))) s[i] = *(it++);
        return s;
    }
};