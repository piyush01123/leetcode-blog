/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n = mountainArr.length();
        int left = 0, right = n-1, mid;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            int pval = mountainArr.get(mid);
            int lval = mountainArr.get(mid-1);
            int rval = mountainArr.get(mid+1);
            if (pval>lval && pval>rval) break;
            else if (lval<pval && pval<rval) left = mid;
            else if (lval>pval && pval>rval) right=mid;
        }
        int peak = mid;
        left = 0;
        right = peak;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            int pval = mountainArr.get(mid);
            if (target==pval) return mid;
            else if (target<pval) right=mid-1;
            else if (target>pval) left=mid+1;
        }
        left = peak;
        right = n-1;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            int pval = mountainArr.get(mid);
            if (target==pval) return mid;
            else if (target<pval) left=mid+1;
            else if (target>pval) right=mid-11;
        }
        return -1;
    }
};