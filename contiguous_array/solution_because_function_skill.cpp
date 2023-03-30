class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int> H;
        int ctr = 0, res=0;
        H[0]={-1};
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==0) ctr++;
            else ctr--;
            if (H.count(ctr)) res=max(res, i-H[ctr]);
            else H[ctr]=i;
        }
        return res;
    }
};