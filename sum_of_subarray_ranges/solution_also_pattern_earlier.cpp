class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long curr = 0;
        int n=nums.size();
        for (int i=0; i<n; i++)
        {
            int min=nums[i], max=nums[i];
            for (int j=i+1; j<n; j++)
            {
                if (nums[j]>max) max=nums[j];
                if (nums[j]<min) min=nums[j];
                curr = curr + (max-min);
            }
        }
        return curr;
    }
};