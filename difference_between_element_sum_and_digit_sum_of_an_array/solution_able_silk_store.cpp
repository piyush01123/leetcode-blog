class Solution {
public:
    int sumOfDigits(int n)
    {
        int res=0;
        while(n)
        {
            res += (n%10);
            n /= 10;
        }
        return res;
    }
    int differenceOfSum(vector<int>& nums) 
    {
        int digitSum=0, elementSum=0;
        for (int n: nums)
        {
            elementSum += n;
            digitSum += sumOfDigits(n);
        }
        return abs(elementSum-digitSum);
    }
};