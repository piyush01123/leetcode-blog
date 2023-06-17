class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        auto cmp = [&nums2](int i, int j){return nums2[i]<nums2[j];};
        sort(indices.rbegin(), indices.rend(), cmp);
        long long curSum=0, res=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; i++)
        {
            int index = indices[i];
            curSum += nums1[index];
            int curMin = nums2[index];
            pq.push(nums1[index]);
            // cout<<i<<','<<index<<','<<curSum<<','<<curMin<<','<<nums1[index]<<endl;
            if (i<k-1) continue;
            if (i>k-1)
            {
                curSum -= pq.top();
                pq.pop();
            }
            res = max(res, curSum*curMin);
        }
        return res;
    }
};