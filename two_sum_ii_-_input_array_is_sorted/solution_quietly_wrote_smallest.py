class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        complements = dict()
        for i,num in enumerate(numbers):
            if num in complements.keys():
                return [complements[num]+1,i+1]
            complements[target-num] = i