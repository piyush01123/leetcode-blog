class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size();
        if(k==1 || k==n) return 0;
        for (int i=0; i<=n-2; i++) weights[i]+=weights[i+1];
        weights.pop_back();

        long long res = 0;
        nth_element(weights.begin(),weights.begin()+k-1,weights.end());
        for (int i=0; i<k-1; i++) res -= weights[i];
        nth_element(weights.begin(),weights.begin()+n-k,weights.end());
        for (int i=0; i<k-1; i++) res += weights[n-2-i];
        return res;
    }
};