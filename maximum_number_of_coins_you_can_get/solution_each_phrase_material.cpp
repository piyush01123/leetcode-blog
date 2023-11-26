class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(),piles.end());
        int i=0, j=piles.size()-1, res=0;
        while(i<j)
        {
            res += piles[j-1];
            i++;
            j--;
            j--;
        }
        return res;        
    }
};