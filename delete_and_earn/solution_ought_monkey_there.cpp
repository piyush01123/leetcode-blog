class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int N=10000;
        vector<int> counts(N, 0);
        for (int n: nums) counts[n-1]+=n;
        vector<int> res(N, 0);
        res[0] = counts[0]; res[1]=max(counts[0],counts[1]);
        for (int i=2; i<N; i++)
        {
            res[i] = max(res[i-1], res[i-2]+counts[i]);
        }
        return res[N-1];
    }
};