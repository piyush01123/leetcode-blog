class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>>pegs(10,vector<int>(3,0));
        for (int i=0; i<rings.size(); i+=2)
        {
            char color = rings[i], rod_ = rings[i+1];
            int rod = rod_-'0';
            if(color=='R') pegs[rod][0]++;
            if(color=='G') pegs[rod][1]++;
            if(color=='B') pegs[rod][2]++;
        }
        int res = 0;
        for (int i=0; i<10; i++)
            if(pegs[i][0]>0 && pegs[i][1]>0 && pegs[i][2]>0) res++;
        return res;
    }
};