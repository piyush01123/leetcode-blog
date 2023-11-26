class Solution {
public:
    int bulbSwitch(int n) 
    {
        if (n==0) return n;
        if (n<4) return 1;
        int lo=0, hi=n/2, mid;
        while (lo<=hi)
        {
            mid = lo + (hi-lo)/2;
            if (n/mid==mid) return mid;
            else if (n/mid > mid) lo = mid+1;
            else if (n/mid < mid) hi = mid-1;
        }
        return lo-1;
    }
};