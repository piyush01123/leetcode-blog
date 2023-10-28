class Solution {
public:
    int countVowelPermutation(int n) 
    {
        int mod=1e9+7;
        vector<int> A = {1,1,1,1,1};
        for(int i=1; i<n; i++)
            A = {A[1], \
                (A[0]+A[2])%mod, \
                (((A[0]+A[1])%mod+A[3])%mod+A[4])%mod, \
                (A[2]+A[4])%mod, \
                A[0]};
        return ((((A[0]+A[1])%mod+A[2])%mod+A[3])%mod+A[4])%mod;
    }
};