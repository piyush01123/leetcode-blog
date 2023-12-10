class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        map<int,int>H;
        for(int num: nums) H[num]++;
        int res=0, ctr=0;
        for(auto it=H.begin(); it!=H.end(); it++) res += it->second*ctr++;
        return res;
    }
};