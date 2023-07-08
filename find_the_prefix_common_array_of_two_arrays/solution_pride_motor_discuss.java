class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) 
    {
        int n=A.length, cur=0;
        boolean[] vecA = new boolean[n];
        boolean[] vecB = new boolean[n];
        for(int i=0; i<n; i++) vecA[i]= vecB[i] = false;
        int[] res = new int[n];
        for(int i=0; i<n; i++)
        {
            int a=A[i]-1, b=B[i]-1;
            cur = cur + (vecB[a]?1:0) + (vecA[b]?1:0);
            if (a==b) cur++;
            vecA[a] = true;
            vecB[b] = true;
            res[i] = cur;
        }
        return res;        
    }
}