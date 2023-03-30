class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) 
    {
        int n = quality.size();
        vector<pair<int,int>> workers;
        for (int i=0; i<n; i++) workers.push_back({quality[i],wage[i]});
        auto comp = [](pair<int,int> w1, pair<int,int>w2)\
        {return (double)w1.second/w1.first < (double)w2.second/w2.first;};
        sort(workers.begin(), workers.end(), comp);
        priority_queue<int> pq;
        double res = INT_MAX;
        int curSum = 0;
        for (auto &worker: workers)
        {
            int qual = worker.first, wage = worker.second;
            curSum += qual;
            pq.push(qual);
            if (pq.size()<k) continue;
            if (pq.size()>k)
            {
                curSum -= pq.top();
                pq.pop();
            }
            res = min(res, (double)curSum * wage / qual);
        }
        return res;
    }
};