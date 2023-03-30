class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ctr=0, res=0, n=nums.size();
        unordered_map<int,int> H;
        H[0]=-1;
        for (int i=0; i<n; i++)
        {
            if (nums[i]==1) ctr++;
            else ctr--;
            if (H.count(ctr)) res = max(res, i-H[ctr]);
            else H[ctr]=i;
        }
        return res;
    }
};