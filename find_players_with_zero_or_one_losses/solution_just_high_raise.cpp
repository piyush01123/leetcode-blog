class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        unordered_map<int,pair<int,int>> H;
        for (auto &match: matches)
        {
            int winner=match[0], loser=match[1];
            if (!H.count(winner)) H[winner] = {1,0};
            else H[winner].first += 1;
            
            if (!H.count(loser)) H[loser] = {0,1};
            else H[loser].second += 1;
        }
        
        vector<int> A,B;
        for (auto &triplet: H)
        {
            int player=triplet.first;
            int wins=triplet.second.first, losses=triplet.second.second;
            if (losses==0) A.push_back(player);
            if (losses==1) B.push_back(player);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        return vector<vector<int>>{A,B};
    }
};