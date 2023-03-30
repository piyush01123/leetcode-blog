class Solution {
public:
    void swap(int &a, int&b)
    {
        int t=a;
        a=b;
        b=t;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1) return;
        int n=nums.size(), i;
        for (i=n-2; i>=0; i--)
            if (nums[i+1]>nums[i]) break;
        if (i==-1) {reverse(nums.begin(),nums.end()); return;}
        sort(nums.begin()+i+1, nums.end());
        int j;
        for (j=i+1; j<n; j++) if (nums[j]>nums[i]) break;
        swap(nums[i],nums[j]);
        return;
    }
};