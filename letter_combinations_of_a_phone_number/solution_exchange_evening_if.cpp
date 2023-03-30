class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        unordered_map<char,vector<char>> mapping;
        mapping['2']={'a','b','c'};
        mapping['3']={'d','e','f'};
        mapping['4']={'g','h','i'};
        mapping['5']={'j','k','l'};
        mapping['6']={'m','n','o'};
        mapping['7']={'p','q','r','s'};
        mapping['8']={'t','u','v'};
        mapping['9']={'w','x','y','z'};
        vector<string>words {""};
        for (char digit: digits)
        {
            vector<string> new_words;
            for (string word: words)
                for (char letter: mapping[digit])
                    new_words.push_back(word+letter);
            words=new_words;
        }
        return words;
    }
};