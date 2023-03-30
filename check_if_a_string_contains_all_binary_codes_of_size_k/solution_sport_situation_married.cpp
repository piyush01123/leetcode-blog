class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> S;
        int n=s.size();
        for (int i=0; i<n-k+1; i++) S.insert(string(s.begin()+i,s.begin()+i+k));
        return S.size()==(1<<k);
    }
};