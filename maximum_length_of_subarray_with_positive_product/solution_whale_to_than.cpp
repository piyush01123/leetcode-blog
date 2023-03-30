class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int l_pos=0, l_neg=0, res=0;
        for (int n: nums)
        {
            if (n==0)
            {
                l_pos=0;
                l_neg=0;
            }
            if (n>0)
            {
                l_pos++;
                l_neg = l_neg==0?0:l_neg+1;
            }
            if (n<0)
            {
                int t=l_pos;
                l_pos = l_neg==0?0:l_neg+1;
                l_neg = t+1;
            }
            res = max(res, l_pos);
        }
        return res;
    }
};