class Solution {
public:
    int sumCounts(vector<int>& nums) 
    {
        int res=0, n=nums.size();
        for (int i=0; i<n; i++) for (int j=i; j<n; j++) 
        {
            auto nset = unordered_set<int>(nums.begin()+i,nums.begin()+j+1);
            res += nset.size()*nset.size();
        }
        return res;
    }
};