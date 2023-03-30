class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>H;
        for(int n: nums)
        {
            if(H.find(n)==H.end())H[n]=1;
            else H[n]++;
            if (H[n]>nums.size()/2) return n;
        }
        return -1;
    }
};