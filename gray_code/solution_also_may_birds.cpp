class Solution {
public:
    vector<int> grayCode(int n) {
        if (n==1) return {0,1};
        vector<int> last = grayCode(n-1);
        vector<int> res = last;
        reverse(last.begin(), last.end());
        for (int v: last) res.push_back(v+(1<<(n-1)));
        return res;
    }
};