class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg = x<0
        y = str(abs(x))
        z = int(''.join(list(reversed(y))))
        if abs(x) > 2**31 or abs(z) > 2**31:
            return 0
        return -z if neg else z
        
        