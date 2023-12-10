class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int cur = 0, n=pref.size(), prefix=0;
        vector<int> res;
        for (int i=0; i<n; i++)
        {
            res.push_back(prefix ^ pref[i]);
            prefix ^= res.back();
        }
        return res;     
    }
};