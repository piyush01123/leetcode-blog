class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res((1<<n),0);
        for (int i=1; i<(1<<n); i++) res[i] = i^(i>>1);
        return res;
    }
};