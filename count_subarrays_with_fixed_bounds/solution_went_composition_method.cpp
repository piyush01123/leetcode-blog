class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        int n = nums.size(), minIdx=-1, maxIdx=-1, badIdx=-1;
        long long res = 0;
        for (int i=0; i<n; i++)
        {
            if (nums[i]<minK || nums[i]>maxK)
            {
                badIdx = i;
                continue;
            }
            if (nums[i]==minK) minIdx = i;
            if (nums[i]==maxK) maxIdx = i;            
            if(minIdx!=-1 && maxIdx!=-1) 
            {
                int valIdx = min(minIdx, maxIdx);
                if (valIdx>badIdx) res += (valIdx-badIdx);
            }
        }
        return res;
    }
};