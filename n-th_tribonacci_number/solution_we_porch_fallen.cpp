class Solution {
public:
    int tribonacci(int n) {
        if (n==0) return 0;
        if (n<=2) return 1;
        vector<int> tribs(n+1,0); tribs[1]=1; tribs[2]=1;
        for (int i=3; i<=n; i++) tribs[i]=tribs[i-3]+tribs[i-2]+tribs[i-1];
        return tribs[n];
    }
};