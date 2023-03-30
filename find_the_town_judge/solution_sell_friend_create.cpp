class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n,0), outDegrees(n,0);
        for (auto pair: trust) {
            inDegrees[pair[1]-1]++;
            outDegrees[pair[0]-1]++;
        }
        for (int i=0; i<n; i++) if (inDegrees[i]==n-1 && outDegrees[i]==0) return i+1;
        return -1;
    }
};