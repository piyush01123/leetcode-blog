class Solution {
public:
    string sortVowels(string s) 
    {
        unordered_set<char> vowels;
        for (char ch: "aeiouAEIOU") vowels.insert(ch);
        vector<int> vowel_positions;
        vector<char> vowels_in_s;
        for(int i=0; i<s.length(); i++) if (vowels.count(s[i]))
        {
            vowel_positions.push_back(i);
            vowels_in_s.push_back(s[i]);
        }
        sort(vowels_in_s.begin(), vowels_in_s.end());
        for (int i=0; i< vowels_in_s.size(); i++) s[vowel_positions[i]]= vowels_in_s[i];
        return s;
    }
};