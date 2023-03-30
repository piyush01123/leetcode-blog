class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=0, n=nums.size();
        for (int n: nums) if (n==1) ones++;
        vector<int> numsTwice(2*n);
        for (int i=0; i<n; i++) numsTwice[i]=nums[i];
        for (int i=0; i<n; i++) numsTwice[n+i]=nums[i];
        int curr=0;
        for (int i=0; i<ones; i++) curr+=numsTwice[i];
        int res=curr;
        for (int i=ones; i<2*n; i++)
        {
            curr += numsTwice[i]-numsTwice[i-ones];
            res = max(res,curr);
        }
        return ones-res;
    }
};