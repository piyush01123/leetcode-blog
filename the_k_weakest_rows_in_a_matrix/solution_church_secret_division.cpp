class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i=0; i<mat.size(); i++)
        {
            auto row=mat[i];
            int s = accumulate(row.begin(), row.end(), 0);
            pq.push(make_pair(s,i));
        }
        vector<int> res;
        cout << pq.top().first << ' ' << pq.top().second;
        while (res.size()<k)
        {
            pair<int,int> top=pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        return res;
    }
};