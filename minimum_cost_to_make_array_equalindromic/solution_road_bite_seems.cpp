class Solution {
public:
    long long minimumCost(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median = (n%2) ? nums[n/2] : (nums[n/2]+nums[n/2-1])/2;
        long long minCost = LLONG_MAX;
        int cand1=median, cand2=median;
        while(cand1>0 && !isPalindrome(to_string(cand1))) cand1--;
        while(!isPalindrome(to_string(cand2))) cand2++;
        return min(calculateCost(nums,cand1), calculateCost(nums,cand2));
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