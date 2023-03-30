# class Solution:
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         comps = set()
#         comp_idx = {}
#         for i, num in enumerate(nums):
#             # print(i)
#             if num in comps:
#                 return [comp_idx[num], i]
#             else:
#                 comps.add(target-num)
#                 comp_idx[target-num] = i
#         return False

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_table = {}
        for i in range(0,len(nums)):
            if nums[i] not in hash_table:
                hash_table[nums[i]] = [i]
            else:
                hash_table[nums[i]].append(i)
        
        for k,v in hash_table.items():
            check_key = target - k
            if check_key in hash_table:
                for x in hash_table[check_key]:
                    for v in v:
                        if x == v:
                            continue
                        else:
                            return [v,x]
                    
                
  
        return -1