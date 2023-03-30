class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int lo=0, hi=nums.size()-1, i=0;
        while (i<=hi)
        {
            // cout <<"IN"<< i << lo <<  hi << endl;
            if (nums[i]==0)
            {
                nums[i] = nums[lo];
                nums[lo] = 0;
                lo++;
                i++;
            }
            else if (nums[i]==2)
            {
                nums[i] = nums[hi];
                nums[hi] = 2;
                hi--;
            }
            else
                i++;
            // cout <<"OUT"<< i << lo <<  hi << endl;
        }
    }
};