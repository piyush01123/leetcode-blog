class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(), i=0, res=0;
        while (i<n-2)
        {
            int start=i;
            while (i<n-2 && nums[i+1]-nums[i]==nums[i+2]-nums[i+1]) i++;
            int L = i+2-start;
            int num_subs = (L-2)*(L-1)/2;
            res += num_subs;
            i++;
        }
        return res;
    }
};