class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # Sol 1: AC
        # complements = dict()
        # for i,num in enumerate(numbers):
        #     if num in complements.keys():
        #         return [complements[num]+1,i+1]
        #     complements[target-num] = i

        # Sol2
        n = len(numbers)
        lo,hi = 0,n-1
        while lo<hi:
            if numbers[lo]+numbers[hi]==target:
                return [lo+1,hi+1]
            elif numbers[lo]+numbers[hi]<target:
                lo+=1
            else:
                hi-=1