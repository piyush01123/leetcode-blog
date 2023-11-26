class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(),piles.end());
        int res=0;
        for (int i=0; i<(int)piles.size()/3; i++) res += piles[piles.size()-2-2*i];
        return res;
    }
};