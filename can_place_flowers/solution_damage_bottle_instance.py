class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        count=0
        i=0
        while i < len(flowerbed):
            if flowerbed[i]==0 and (i==0 or flowerbed[i-1]==0) and (i==len(flowerbed)-1 or flowerbed[i+1]==0):
                count+=1
                i+=1
            else:
                pass
            print(count)
            i+=1
        print(count)
        return n <= count