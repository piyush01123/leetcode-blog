class Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
        int largestNegative=INT_MIN, n=nums.size(), np=0, nn=0, nz=0;
        if (n==1) return nums[0];
        long long res=1;
        for (int num: nums)
        {
            if (num>0) np++;
            else if (num<0) {largestNegative=max(largestNegative,num); nn++;}
            else {nz++; continue;}
            res *=num;
        }
        if ((np==0 && nn==1 && nz>0)||nz==n) return 0;
        if (nn%2==1) res/=largestNegative;
        return res;
    }
};