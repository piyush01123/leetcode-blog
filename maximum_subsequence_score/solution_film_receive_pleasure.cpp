class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        vector<pair<int,int>> nums;
        for (int i=0; i<n; i++) nums.push_back({nums2[i],nums1[i]});
        sort(nums.rbegin(), nums.rend());
        priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
        long long curSum=0, res=0;
        for (int i=0; i<n; i++)
        {
            int e=nums[i].first, s=nums[i].second;
            // cout<<e<<','<<s<<endl;
            pq.push(s);
            curSum += s;
            if (pq.size()<k) continue;
            if(pq.size()>k)
            {
                int smin = pq.top();
                pq.pop();
                curSum -= smin;
            }
            res = max(res, curSum*e);
        }
        return res;
    }
};