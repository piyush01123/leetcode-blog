class Solution {
public:
    int util(int n, int k)
    {
        if (n==1) return 0;
        int L = (1<<(n-1));
        if (k<L/2) return util(n-1, k);
        else return 1^util(n-1, k-L/2);
    }
    int kthGrammar(int n, int k) 
    {
        return util(n, k-1);
    }
};