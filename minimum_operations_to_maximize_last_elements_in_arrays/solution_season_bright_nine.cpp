class Solution {
public:
    int util(vector<int>&A, vector<int>&B)
    {
        int n=A.size(), ctr=0;
        for (int i=0; i<=n-2; i++)
        {
            if(A[i]<=A[n-1] && B[i]<=B[n-1]) continue;
            else if (A[i]<=B[n-1] && B[i]<=A[n-1]) ctr++;
            else return -1;
        }
        return ctr;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) 
    {
        int a = util(nums1,nums2);
        swap(nums1.back(), nums2.back());
        int b = util(nums1,nums2);
        if (a==-1 && b==-1) return -1;
        if (a==-1) return 1+b;
        if (b==-1) return a;
        return min(a, 1+b);
    }
};