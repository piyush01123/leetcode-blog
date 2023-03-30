class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int>pos(26,-1);
        for (int i=0; i<s.length(); i++)
        {
            if (pos[s[i]-'a']==-1) pos[s[i]-'a'] = i;
            else
            {
                int d = i - pos[s[i]-'a'] - 1;
                if (d!=distance[s[i]-'a']) return false;
            }
        }
        return true;
    }
};