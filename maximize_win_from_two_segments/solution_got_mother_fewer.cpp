class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) 
    {
        int n=prizePositions.size(), i=0, j=0, res=0;
        if (n<=2) return n;
        vector<int>dp(n+1,0);
        for (int i=0; i<n; i++)
        {
            while(prizePositions[j]<prizePositions[i]-k) j++;
            int len_seg = i-j+1;
            dp[i+1] = max(dp[i], len_seg);
            res = max(res, dp[j]+len_seg);
            // cout<<'I'<<i<<'J'<<j<<endl;
        }
        // for(int x:dp)cout<<x<<',';cout<<endl;
        return res;
    }
};

//  1,1,2,2,3,3,5
//0,1,2,3,4,5,6,(6,3)
// ,1,2,3,4,5,6,7