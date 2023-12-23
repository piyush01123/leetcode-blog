class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int a=-1, b=-1;
        for(int num: nums)
        {
            if(num>a) {b = a; a = num;}
            else if (num>b) b = num;
        }
        return (a-1)*(b-1);
    }
};