class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; i++) nums.push_back(nums[i]);

        stack<pair<int,int>> S;
        vector<int> res (2*n,-1);
        
        for (int i=0; i<2*n; i++)
        {
            while (!S.empty() && nums[i] > S.top().first)
            {
                res[S.top().second] = nums[i];
                S.pop();
            }
            S.push({nums[i],i});
        }
        return vector<int>(res.begin(), res.begin()+n);
    }
};