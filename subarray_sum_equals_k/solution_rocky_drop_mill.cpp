#define ll long long
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), res=0; ll curr=0;
        unordered_map<ll,int> H;
        H[0] = 1; // At i=-1 we have seen 0
        for (int i=0; i<n; i++)
        {
            curr+=nums[i];
            if (H.count(curr-k)) res+=H[curr-k];
            H[curr]++;
        }
        return res;
    }
};