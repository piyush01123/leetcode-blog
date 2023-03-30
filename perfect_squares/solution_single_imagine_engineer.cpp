class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> A = vector<int>{0,1};
        for (int i=2; i<=n; i++)
        {
            int curMin = i;
            for (int j=1; j*j<=i; j++)
            {
                if (j*j==i)
                {curMin=1; break;}
                curMin = min(curMin, A[j*j]+A[i-j*j]);
            }
            A.push_back(curMin);
        }
        return A[n];
    }
};