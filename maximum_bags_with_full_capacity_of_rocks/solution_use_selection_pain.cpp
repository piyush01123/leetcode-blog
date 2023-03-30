class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int n = capacity.size(), ctr=0;
        vector<int> remainingCap = vector<int>(n,-1);
        for (int i=0; i<n; i++) remainingCap[i]=capacity[i]-rocks[i];
        sort(remainingCap.begin(),remainingCap.end());
        // for (int i=0; i<n; i++)
        // {
        //     additionalRocks-=remainingCap[i];
        //     if (additionalRocks<0) break;
        //     ctr++;
        // }
        while (ctr<n && additionalRocks>=0) additionalRocks-=remainingCap[ctr++];
        return (additionalRocks<0 ? ctr-1 : ctr);
    }
};