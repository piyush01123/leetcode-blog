class Solution {
public:
    bool possible(int capacity, int days, vector<int>&weights)
    {
        int n=weights.size(), i=0, ctr=0;
        while(i<n)
        {
            if (weights[i]>capacity) return false;
            int cur = 0;
            while(i<n && cur+weights[i]<=capacity)
            {
                cur += weights[i];
                i++;
            }
            ctr ++;
        }
        return (ctr<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int lo=0, hi=INT_MAX;
        while (lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if (possible(mid, days, weights)) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};