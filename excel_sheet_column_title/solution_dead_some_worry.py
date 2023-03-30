class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = []
        while n>0:
            n, r = divmod(n, 26)
            if r==0:
                r = 26
                n = n-1
            res.append(r)
        return "".join(chr(n-1 + ord('A')) for n in res[::-1])
