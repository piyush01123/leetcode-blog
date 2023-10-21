class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back({});
        int i=0, n=nums.size();
        while(i<n)
        {
            int cur = nums[i], j=i;
            while(j<n && nums[j]==cur) j++;
            int rep = j-i;
            i = j;
            int m = res.size();
            for(int j=0; j<m; j++)
            {
                vector<int> vec = res[j];
                for(int k=0; k<rep; k++)
                {
                    vec.push_back(cur);
                    res.push_back(vec);
                }
            }
        }
        return res;
    }
};