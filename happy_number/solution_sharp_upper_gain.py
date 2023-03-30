class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        encountered = []
        while True:
            print(n)
            digits = list(map(int, str(n)))
            n = sum(i**2 for i in digits)
            if n==1:
                return True
            if n in encountered:
                return False
            encountered.append(n)
    