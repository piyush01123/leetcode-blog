class Solution {
public:
    int mySqrt(int x) {
        if (x==0 || x==1) return x;
        int lo = 1, hi=x, mid;
        while (lo<=hi)
        {
            mid = lo + (hi-lo)/2;
            if (mid == x/mid) return mid;
            if (mid > x/mid && (mid-1) < x/(mid-1)) return mid-1;
            if (mid < x/mid) lo = mid+1;
            else hi = mid-1;
        }
        if (mid == x/mid) return mid;
        if (mid > x/mid && (mid-1) < x/(mid-1)) return mid-1;
        return mid;
    }
};