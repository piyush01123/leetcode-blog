class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n=A.size(), cur=0;
        vector<bool> vecA(n,false), vecB(n,false);
        vector<int>res(n,0);
        for(int i=0; i<n; i++)
        {
            int a=A[i]-1, b=B[i]-1;
            cur = cur+vecB[a]+vecA[b];
            if (a==b) cur++;
            vecA[a] = true;
            vecB[b] = true;
            res[i] = cur;
        }
        return res;
    }
};