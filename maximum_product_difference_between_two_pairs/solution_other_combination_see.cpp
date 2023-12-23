class Solution {
public:
    int maxProductDifference(vector<int>& nums) 
    {
        int min1=INT_MAX, min2=INT_MAX, max1=INT_MIN, max2=INT_MIN;
        for(int a: nums)
        {
            if(a<min1){min2=min1; min1=a;}
            else if(a<min2) min2=a;
            if(a>max1){max2=max1; max1=a;}
            else if (a>max2) max2=a;
        }
        return max1*max2 - min1*min2;
    }
};