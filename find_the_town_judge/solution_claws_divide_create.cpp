class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>counter(n,0);
        for (auto pair: trust)
        {
            int truster=pair[0]-1, trusted=pair[1]-1;
            counter[truster]=-1;
            if (counter[trusted]!=-1) counter[trusted]++;
        }
        for (int i=0; i<n; i++) if (counter[i]==n-1) return i+1;
        return -1;
    }
};