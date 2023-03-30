class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cumSumFreq = {}
        cumSum = 0
        counter = 0
        for num in nums:
            cumSum += num
            if cumSum==k:
                counter += 1
            if cumSum-k in cumSumFreq:
                counter += cumSumFreq[cumSum-k]
            if cumSum in cumSumFreq:
                cumSumFreq[cumSum] += 1
            else:
                cumSumFreq[cumSum] = 1
        return counter