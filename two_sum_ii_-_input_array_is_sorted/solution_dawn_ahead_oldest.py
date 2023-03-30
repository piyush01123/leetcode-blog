class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # Sol 1: AC
        # complements = dict()
        # for i,num in enumerate(numbers):
        #     if num in complements.keys():
        #         return [complements[num]+1,i+1]
        #     complements[target-num] = i

        # Sol2: AC
        # n = len(numbers)
        # lo,hi = 0,n-1
        # while lo<hi:
        #     if numbers[lo]+numbers[hi]==target:
        #         return [lo+1,hi+1]
        #     elif numbers[lo]+numbers[hi]<target:
        #         lo+=1
        #     else:
        #         hi-=1
        
        # Sol3
        n = len(numbers)
        for i in range(n):
            l, r = i + 1, n - 1
            tmp = target - numbers[i]
            while l <= r:
                mid = l + (r-l) // 2
                if numbers[mid] == tmp:
                    return([i + 1, mid + 1])
                elif numbers[mid] < tmp:
                    l = mid + 1
                else:
                    r = mid - 1
        