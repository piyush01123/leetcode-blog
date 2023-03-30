class Solution:
    def squareFreeSubsets(self, nums: List[int]) -> int:
        mod = 1_000_000_007
        primes = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
        mask = [-1]*31 
        mask[1] = 0 
        for x in range(2, 31): 
            m, v = 0, 1
            for i, p in enumerate(primes): 
                if x % p == 0: 
                    v *= p 
                    m ^= 1<<i
            if v == x: mask[x] = m 
        n = len(nums)
        dp = [[0]*(1<<10) for _ in range(n+1)]
        for j in range(1<<10): dp[n][j] = 1
        for i in range(n-1, -1, -1): 
            dp[i] = dp[i+1]
            m = mask[nums[i]]
            if m<0: continue
            for j in range(1<<10): 
                if j & m == 0: 
                    dp[i][j] = (dp[i][j] + dp[i+1][j ^ m]) % mod
        return (dp[0][0] - 1) % mod