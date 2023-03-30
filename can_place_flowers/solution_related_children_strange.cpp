class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n==0) return true;
        int N = flowerbed.size(), S = accumulate(flowerbed.begin(),flowerbed.end(),0);
        if (N-S<n) return false;
        for (int i=0; i<N; i++)
        {
            if (flowerbed[i]==0)
            {
                bool cond1 = i==0 || flowerbed[i-1]==0;
                bool cond2 = i==N-1 || flowerbed[i+1]==0;
                if (cond1 && cond2) {n--;flowerbed[i]=1;}
                if (n==0) return true;
            }
        }
        return false;
    }
};