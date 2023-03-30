class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>> H;
        for (int i=0; i<s.size(); i++)
            H[s[i]].push_back(i);
        int res=s.size();
        for (auto pair: H)
        {
            if (pair.second.size()==1) 
                res=min(res,pair.second[0]);
        }
        if (res==s.size()) res = -1;
        return res;
    }
};