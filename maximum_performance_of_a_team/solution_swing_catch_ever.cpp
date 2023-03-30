class Solution 
{
    int mod = 1000000007;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, \
    int k) 
    {
        vector<pair<int,int>> nums;
        for (int i=0; i<n; i++) nums.push_back({efficiency[i],speed[i]});
        sort(nums.rbegin(), nums.rend());
        priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
        long long curSum=0, res=0;
        for (auto &[e,s]: nums)
        {
            pq.push(s);
            curSum += s;
            if(pq.size()>k)
            {
                int smin = pq.top();
                pq.pop();
                curSum -= smin;
            }
            res = max(res, curSum*e);
        }
        return (res%mod);
    }
};