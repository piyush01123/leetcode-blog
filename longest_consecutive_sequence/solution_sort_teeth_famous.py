class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        arr = set(nums)
        max_len = 0
        for num in arr:
            if num - 1 not in arr:
                curr_len = 1
                curr_num = num
                while curr_num + 1 in arr:
                    curr_num += 1
                    curr_len += 1
                max_len = max(max_len, curr_len)
            else:
                # We only want to start building the sequence from the smallest member
                continue
        return max_len

        