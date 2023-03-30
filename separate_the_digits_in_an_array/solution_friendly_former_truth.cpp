class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int> res;
        for(int n: nums)
        {
            vector<int>digits;
            while(n>0)
            {
                digits.push_back(n%10);
                n/=10;
            }
            reverse(digits.begin(),digits.end());
            for (int d: digits) res.push_back(d);
        }
        return res;
    }
};