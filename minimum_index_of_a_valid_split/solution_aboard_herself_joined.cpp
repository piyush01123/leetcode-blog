class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int> H;
        for(int num: nums) H[num]++;
        int mfi=-1, mfreq=-1;
        for(auto &[item,freq]: H) if (freq>n/2) {mfi=item; mfreq=freq;}
        int ctr=0;
        for (int i=0; i<n-1; i++)
        {
            if (nums[i]==mfi) ctr++;
            bool valLeft = (ctr > (i+1)/2);
            bool valRight = (mfreq-ctr > (n-i-1)/2);
            if (valLeft && valRight) return i;
        }
        return -1;
    }
};