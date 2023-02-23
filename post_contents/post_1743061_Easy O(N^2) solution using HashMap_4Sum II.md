Create a hashmap H of all possible sums of `nums1` and `nums2` in O(N^2) time.
Then traverse `nums3`X`nums4` in O(N^2) time and each time check membership in H.
Easy-peasy!

C++ version:
```
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
```
Python version:
```
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        H = collections.defaultdict(int)
        res = 0
        for n1 in nums1:
            for n2 in nums2:
                H[n1+n2]+=1
        for n3 in nums3:
            for n4 in nums4:
                if -(n3+n4) in H:
                    res += H[-(n3+n4)]
        return res
```