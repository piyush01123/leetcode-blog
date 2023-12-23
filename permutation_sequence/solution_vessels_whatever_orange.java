class Solution {
    void swap(int i, int j){int t=digits[i]; digits[i]=digits[j]; digits[j]=t;}
    int[] digits;
    public String getPermutation(int n, int k)
    {
        digits = new int[n];
        int[] F = new int[n+1]; F[0]=1;
        int p=1, pos=0; k--;
        for(int i=1; i<=n; i++){digits[i-1]=i; F[i]=i*F[i-1];}
        while(n-->0)
        {
            int cur = k / F[n];
            k %= F[n];
            swap(pos+cur, pos);
            Arrays.sort(digits,  (++pos), digits.length);
        }
        String res="";
        for (int digit: digits) res+=Integer.toString(digit);
        return res;
    }
};
