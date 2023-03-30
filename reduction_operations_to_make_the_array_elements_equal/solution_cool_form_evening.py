class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        # n = len(nums)
        # nums = sorted(nums)
        freq = dict()
        for num in nums:
            if num not in freq.keys():
                freq[num]=1
            else:
                freq[num]+=1
        sorted_unique_nums = sorted(list(freq.keys()))[::-1]
        n = len(sorted_unique_nums)
        # print(freq, sorted_unique_nums, n)
        if n==1:
            return 0
        for i in range(1,n-1):
            freq[sorted_unique_nums[i]]+=freq[sorted_unique_nums[i-1]]
            # print(freq[sorted_unique_nums[i]])
        # print("MOdified freq", freq, )
        s = 0
        for i in range(n-1):
            s += freq[sorted_unique_nums[i]]
            # print("s=",s)
        # print("ANS", s)
        return s