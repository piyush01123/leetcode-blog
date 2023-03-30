class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size(), cur=weights[0];
        if(k==1 || n==k) return 0;
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for (int i=1; i<n; i++)
        {
            if (i>=2) cur -= weights[i-2];
            cur += weights[i];
            max_pq.push(cur);
            min_pq.push(cur);

        }
        long long res = 0;
        for (int i=0; i<k-1; i++)
        {
            res += max_pq.top();
            res -= min_pq.top();
            max_pq.pop();
            min_pq.pop();
        }
        return res;
    }
};