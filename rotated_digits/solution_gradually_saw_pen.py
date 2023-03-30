class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        memo={}
        memo[1] = False
        if N in memo:
            return sum(memo[i] for i in range(1, N+1))
        else:
            digits = list(map(int, str(N)))
            if 3 in digits or 4 in digits or 7 in digits or set(digits) <= set([0, 1, 8]):
                memo[N] = False
                return self.rotatedDigits(N-1)
            else:
                memo[N] = True
                return self.rotatedDigits(N-1) + 1
            
        
        