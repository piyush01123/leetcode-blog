class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n=dist.size();
        vector<float> times;
        for (int i=0; i<n; i++) times.push_back((float)dist[i]/speed[i]);
        sort(times.begin(),times.end());
        for (int i=0; i<n; i++) if (i>=times[i]) return i;
        return n;
    }
};