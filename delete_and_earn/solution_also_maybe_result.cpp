class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int N=10000;
        vector<int> counts(N, 0);
        for (int n: nums) counts[n-1]++;
        vector<int> res(N, 0);
        res[0] = counts[0]*1; res[1]=max(counts[0]*1,counts[1]*2);
        for (int i=2; i<N; i++)
        {
            res[i] = max(res[i-1], res[i-2] + (i+1)*counts[i]);
        }
        return res[N-1];
    }
};