class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), res=0;
        unordered_map<int,int> H;
        for (int n1: nums1) for (int n2: nums2) H[n1+n2]++;
        for (int n3: nums3) for (int n4: nums4) if (H.count(-(n3+n4))) res+=H[-(n3+n4)];
        return res;
    }
};