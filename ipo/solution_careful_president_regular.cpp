class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, \
                             vector<int>& capital) 
    {
        int n = profits.size();
        vector<pair<int,int>> cap_prof;
        for (int i=0; i<n; i++) cap_prof.push_back({capital[i],profits[i]});
        sort(cap_prof.begin(), cap_prof.end());
        priority_queue<int> pq;
        int cur = 0;
        for (int i=0; i<k;  i++)
        {
            while(cur<n && cap_prof[cur].first<=w)
                pq.push(cap_prof[cur++].second);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};