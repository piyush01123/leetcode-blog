class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows==1) return s;
        int m = 2*numRows - 2;
        vector<string> rows(numRows, "");
        for (int i=0; i<s.length(); i++)
        {
            int r = i%m;
            if (r<numRows) rows[r].push_back(s[i]);
            else rows[m-r].push_back(s[i]);
        }
        string res = "";
        for (string r: rows) res+=r;
        return res;
    }
};