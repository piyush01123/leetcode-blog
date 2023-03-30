class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long>scores(n,0);
        for (int i=0; i<n; i++)
            scores[edges[i]] += i;
        return max_element(scores.begin(),scores.end())-scores.begin();
    }
};