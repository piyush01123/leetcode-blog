class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s=set()
        A = []
        for num in nums:
            if num in s:
                A.append(num)
            else:
                s.add(num)
        return A
        