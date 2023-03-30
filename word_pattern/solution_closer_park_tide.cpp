class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s); string w; vector<string>words;
        while(getline(ss,w,' ')) words.push_back(w);
        if (pattern.size()!=words.size()) return false;
        unordered_map<string,char>w2l; unordered_map<char,string>l2w;
        for (int i=0; i<words.size(); i++)
        {
            string word = words[i]; char ch = pattern[i];
            if (w2l.find(word)!=w2l.end() && w2l[word]!=ch) return false;
            if(l2w.find(ch)!=l2w.end() && l2w[ch]!=word) return false;
            w2l[word]=ch; l2w[ch]=word;
        }
        return true;
    }
};