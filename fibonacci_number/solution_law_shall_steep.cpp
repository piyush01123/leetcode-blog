class Solution {
public:
    int fib(int n) {
        if (n<2) return n;
        vector<int> fibs = {0,1};
        for (int i=2; i<=n; i++) fibs.push_back(fibs[i-2]+fibs[i-1]);
        return fibs[n];        
    }
};