class Solution {
public:
    long long minimumCost(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median = (n%2) ? nums[n/2] : (nums[n/2]+nums[n/2-1])/2;
        long long minCost = LLONG_MAX;
        for(int x=max(1,median-100000); x<=median+100000; x++)
        {
            if(!isPalindrome(to_string(x))) continue;
            long long cost = calculateCost(nums, x);
            if (cost<minCost) minCost = cost;
        }
        return minCost;
    }
    long long calculateCost(vector<int>&A, int x)
    {
        long long cost = 0;
        for(int a: A) cost += abs(x-a);
        return cost;
    }
    bool isPalindrome(string s)
    {
        int n = s.length();
        for(int i=0; i<n/2; i++) if(s[i]!=s[n-1-i]) return false;
        return true;
    }
};