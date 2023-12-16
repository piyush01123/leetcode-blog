class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate, count = 0;
        for (int n: nums)
        {
            if (n==candidate) count++;
            else if (count==0) {candidate=n; count=1;}
            else count--;
        }
        return candidate;
    }
};