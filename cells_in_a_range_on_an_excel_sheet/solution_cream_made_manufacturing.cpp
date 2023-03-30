class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        char c1=s[0], r1=s[1], c2=s[3], r2=s[4];
        for (char c=c1; c<=c2; c++)
            for (char r=r1; r<=r2; r++)
                {string t=""; t+=c; t+=r; res.push_back(t);}
        return res;
    }
};