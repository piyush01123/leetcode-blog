class Solution {
    int[] digits;
    int[] F;
    void swap(int i, int j)
    {
        int t = digits[i];
        digits[i] = digits[j];
        digits[j] = t;
    }
    void permute(int n, int k, int pos)
    {
        if (n==0) return;
        int cur = k / F[n-1];
        int rem = k % F[n-1];
        swap(cur+pos, pos);
        Arrays.sort(digits, pos+1, digits.length);
        permute(n-1, rem, pos+1);
    }
    public String getPermutation(int n, int k) 
    {
        digits = new int[n];
        F = new int[n+1];
        int p=1; F[0] = 1;
        for(int i=1; i<=n; i++)
        {
            digits[i-1] = i;
            p *= i;
            F[i] = p;
        }
        permute(n,k-1,0);
        String res = "";
        for (int digit: digits) res += Integer.toString(digit);
        return res;
    }
}