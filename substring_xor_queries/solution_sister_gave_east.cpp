class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) 
    {
        unordered_map<int, vector<int>> H;
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]=='0')
            {
                if (!H.count(0)) H[0]={i,i}; 
                continue;
            }
            int num = 0;
            for (int j=i; j<=min(i+31,(int)s.length()-1); j++) 
            {
                num = (num<<1)+(s[j]-'0');
                if (!H.count(num)) H[num] = {i,j};
            }
        }
        vector<vector<int>> res;
        for (auto &query: queries)
        {
            int val = query[0]^query[1];
            if (H.count(val)) res.push_back(H[val]);
            else res.push_back({-1,-1});
        }
        return res;
    }
};