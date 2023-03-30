class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int cumMod = 0, res=0;
        vector<int> modCtr(k,0);
        modCtr[0] = 1;
        for (int n: nums)
        {
            cumMod = (((cumMod+n)%k)+k)%k;
            res += modCtr[cumMod];
            modCtr[cumMod]++;
        }
        return res;
    }
};