class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int>H;
        for (int &n: arr) 
            if (!H.count(n)) H[n] = 1;
            else H[n]++;
        unordered_set<int> S;
        for (auto &p: H)
            if (S.count(p.second)) return false;
            else S.insert(p.second);
        return true;        
    }
};