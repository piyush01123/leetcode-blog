class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3  = vector<int>(m+n, 0);
        int i=0, j=0, k=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j]){ nums3[k]=nums1[i]; i++; k++; }
            else { nums3[k]=nums2[j]; j++; k++; }
        }
        while (i<m) { nums3[k]=nums1[i]; i++; k++; }
        while (j<n) { nums3[k]=nums2[j]; j++; k++; }
        int a = (m+n)/2;
        if ((m+n)%2==1) return (double) nums3[a];
        else return ((double)nums3[a]+(double)nums3[a-1])/2;
    }
};