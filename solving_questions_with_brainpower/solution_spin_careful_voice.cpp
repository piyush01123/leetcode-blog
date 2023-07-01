class Solution {
    vector<long long> memo;
public:
    long long mostPoints(vector<vector<int>>& questions, int start=0)
    {
        if (start>=questions.size()) return 0;
        if (start==0){memo = vector<long long>(questions.size(),-1);}
        if (memo[start]!=-1) return memo[start];
        int points = questions[start][0], skips = questions[start][1];
        long long a = (long long)points + mostPoints(questions, start+skips+1);
        long long b = mostPoints(questions, start+1);
        return memo[start] = max(a,b);
    }
};