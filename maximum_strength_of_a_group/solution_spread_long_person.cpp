class Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
        if (nums.size()==1) return nums[0];
        bool hasZero=false;
        vector<int>positives, negatives;
        for(int num: nums) if (num>0) positives.push_back(num); else if (num<0) negatives.push_back(num); else hasZero=true;
        sort(negatives.begin(),negatives.end());
        int np=positives.size(), nn=negatives.size();
        if (np==0 && nn==0) return 0;
        if (np==0 && nn==1 && hasZero) return 0;
        long long res=1;
        for(int p: positives) res*=p;
        if (nn%2==0){for(int n:negatives) res*=n;}
        else for(int i=0;i<nn-1;i++) {res*=negatives[i];}
        return res;
    }
};