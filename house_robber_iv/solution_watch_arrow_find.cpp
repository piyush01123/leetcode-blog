class Solution {
public:
    int minCapability(vector<int>& nums, int k) 
    {
        int left = *min_element(nums.begin(),nums.end());
        int right= *max_element(nums.begin(),nums.end());
        while (left<right)
        {
            int i=0, ctr=0, capab=left+(right-left)/2;
            while(i<nums.size())
            {
                if (nums[i]<=capab)
                {
                    i+=2;
                    ctr++;
                }
                else i++;
            }
            if (ctr>=k) right=capab;
            else left = capab+1;
        }
        return left;
    }
};