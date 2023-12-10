class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n=A.size();
        vector<int> res(n,0), indicesA(n);
        for(int i=0; i<n; i++) indicesA[A[i]-1]=i;
        for(int i=0; i<n; i++)
        {
            int b = B[i]-1;
            res[max(i,indicesA[b])]++;
        }
        for(int i=1; i<n; i++)res[i]+=res[i-1];
        return res;
    }
};