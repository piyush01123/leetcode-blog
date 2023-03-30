class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> H;
        for (string str: strs)
        {
            string strsorted = str;
            sort(strsorted.begin(),strsorted.end());
            if (H.count(strsorted))
            {
                H[strsorted].push_back(str);
                continue;
            }
            H[strsorted] = {str};
        }
        vector<vector<string>>res;
        for (auto p: H) res.push_back(p.second);
        return res;
    }
};