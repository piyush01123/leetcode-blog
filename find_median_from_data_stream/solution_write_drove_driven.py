class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums = []
        self.size = 0
        

    def addNum(self, num: int) -> None:
        self.nums.append(num)
        self.nums.sort()
        self.size += 1

    def findMedian(self) -> float:
        if self.size%2==0:
            i = self.size//2
            j = i-1
            return (self.nums[i]+self.nums[j])/2
        else:
            i = (self.size-1)//2
            return self.nums[i]
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()