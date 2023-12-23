class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size(), n2=nums2.size(), i =0, j=0, k=0;
        vector<int> nums(n1+n2);
        while(i<n1 && j<n2)
            if (nums1[i]<=nums2[j]) nums[k++] = nums1[i++];
            else nums[k++] = nums2[j++];
        while (i<n1) nums[k++] = nums1[i++];
        while (j<n2) nums[k++] = nums2[j++];
        return ((n1+n2)%2) ? nums[(n1+n2)/2] : 0.5 * (nums[(n1+n2)/2] + nums[(n1+n2)/2-1]);
    }
};