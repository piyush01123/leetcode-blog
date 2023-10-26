class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if (s.length()<11) return {};
        unordered_map<string,int> H;
        for (int i=0; i<=s.length()-10; i++) H[s.substr(i,10)]++;
        vector<string> res;
        for (auto [k,v]: H) if (v>1) res.push_back(k);
        return res;
    }
};