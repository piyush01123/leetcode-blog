class Solution 
{
public:
    int kthGrammar(int n, int k) 
    {
        if (n==1) return 0;
        int L = (1<<(n-1));
        if (k<=L/2) return kthGrammar(n-1, k);
        else return 1^kthGrammar(n-1, k-L/2);
    }
};