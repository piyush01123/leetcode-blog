class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int minProd=1, maxProd=1, res=INT_MIN;
        for (int n: nums)
        {
            int a=n, b=n*minProd, c=n*maxProd;
            minProd = min(min(a,b),c);
            maxProd = max(max(a,b),c);
            res = max(res,maxProd);
        }
        return res;
    }
};