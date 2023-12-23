class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n=dist.size();
        vector<float> times;
        for (int i=0; i<n; i++) times.push_back((float)dist[i]/speed[i]);
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(), [&times](int i, int j){return times[i]<times[j];});
        for (int i=0; i<n; i++)
        {
            int index = indices[i];
            if (i>=times[index]) return i;
        }
        return n;
    }
};