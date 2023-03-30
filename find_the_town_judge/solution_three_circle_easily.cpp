class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n==1) return 1?trust.size()==0:-1;
        unordered_map<int,vector<int>>H;
        for (auto pair: trust)
        {
            int truster=pair[0],trusted=pair[1];
            if (H.find(trusted)==H.end())H[trusted]={truster};
            else H[trusted].push_back(truster);
        }
        int possibleJudge=-1;
        for (auto item: H)
        {
            if (item.second.size()==n-1) {possibleJudge=item.first; break;}
        }
        if (possibleJudge==-1) return -1;
        for (auto pair: trust)
        {
            int truster=pair[0],trusted=pair[1];
            if (possibleJudge==truster) return -1;
        }
        return possibleJudge;
        
    }
};