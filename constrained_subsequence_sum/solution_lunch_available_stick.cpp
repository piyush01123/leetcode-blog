class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> pq; //(value,index)
        vector<int> dp(nums.size());
        for (int i=0; i<nums.size(); i++)
        {
            while(!pq.empty() && pq.top().second < i-k) pq.pop(); 
            dp[i] = nums[i] + ( i==0 ? 0 : max(0,pq.top().first) );
            pq.push({dp[i],i});
            // cout<<i<<','<<dp[i]<<','<<pq.top().first<<','<<pq.size()<<endl;
        }
        return *max_element(dp.begin(),dp.end());
    }
};