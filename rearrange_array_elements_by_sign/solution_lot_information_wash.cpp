class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int n: nums) if(n>0) pos.push_back(n); else neg.push_back(n);
        vector<int> res(nums.size(), 0);
        for (int i=0; i<nums.size()/2; i++){res[2*i]=pos[i]; res[2*i+1]=neg[i];}
        return res;
    }
};