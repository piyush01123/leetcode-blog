class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        unordered_map<int,int> H;
        for (int num: nums) H[num]++;
        int ctr = 0;
        for (auto [k,v]: H) 
        {
            if (v==1) return -1;
            else if (v%3==0) ctr += v/3;
            else if (v%6==1) ctr += (2*((v-7)/6)) + 3;
            else if (v%6==2) ctr += (2*((v-2)/6)) + 1;
            else if (v%6==4) ctr += (2*((v-4)/6)) + 2;
            else if (v%6==5) ctr += (2*((v-5)/6)) + 2;
        }
        return ctr;
    }
};