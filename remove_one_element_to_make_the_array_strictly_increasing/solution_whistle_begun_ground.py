class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        n = len(nums)
        ctr = 0
        for i in range(1,n):
            if nums[i]<=nums[i-1]:
                nums1, nums2 = nums.copy(), nums.copy()
                nums1.pop(i-1)
                nums2.pop(i)
                print(nums1, nums2)
                if (nums1==sorted(nums1) and len(set(nums1))==n-1) or (nums2==sorted(nums2) and len(set(nums2))==n-1):
                    return True
                else:
                    return False
            #     ctr += 1
            # if ctr==2:
            #     return False
            # print(nums[i], ctr)
        return True