class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = nums.size(), closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++)
        {
            int lo=i+1, hi=n-1;
            while (lo<hi)
            {
                int curr = nums[i]+nums[lo]+nums[hi];
                if (curr==target) return target;
                if (abs(target-curr)<abs(target-closest)) closest = curr;
                if (curr<target) lo ++;
                else hi--;
            }
        }
        return closest;
    }
};