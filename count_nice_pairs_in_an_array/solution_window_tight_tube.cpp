class Solution {
public:
    int reverse(int x)
    {
        int revx = 0;
        while(x)
        {
            revx = 10*revx + (x%10);
            x/=10;
        }
        return revx;
    }
    int countNicePairs(vector<int>& nums) 
    {
        long res=0, mod=1e9+7;
        unordered_map<int,long> H;
        for (int num: nums) H[num-reverse(num)] ++;
        for (auto &[k,v]: H)
        {
            if (v==1) continue;
            res += (v*(v-1)/2)%mod;
            res %= mod;
        }
        return res;
    }
};