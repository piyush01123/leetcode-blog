class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) 
    {
        long long res=0;
        unordered_set<int> rows_visited, cols_visited;
        for (int i=queries.size()-1; i>=0; i--)
        {
            int rc=queries[i][0], idx=queries[i][1], val=queries[i][2];
            if (rc==0 && !rows_visited.count(idx))
            {
                rows_visited.insert(idx);
                res += (long long)val * (long long)n;
                res -= (long long)val * (long long)cols_visited.size();
            }
            if (rc==1 && !cols_visited.count(idx))
            {
                cols_visited.insert(idx);
                res += (long long)val * (long long)n;
                res -= (long long)val * (long long)rows_visited.size();
            }
        }
        return res;
    }
};