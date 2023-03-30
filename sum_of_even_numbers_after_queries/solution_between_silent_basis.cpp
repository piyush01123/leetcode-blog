class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(queries.size(),-1);
        int S = 0;
        for (int n: nums) if (n%2 == 0) S+=n;
        for (int q=0; q<queries.size(); q++)
        {
            int val=queries[q][0], index = queries[q][1];
            if (nums[index]%2 == 0) S-=nums[index];
            nums[index] += val;
            if (nums[index]%2 == 0) S+=nums[index];
            res[q] = S;
        }
        return res;
    }
};