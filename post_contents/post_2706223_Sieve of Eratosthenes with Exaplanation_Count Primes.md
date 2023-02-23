Sieve of Eratosthenes is the well known algorithm for such count/print primes type problems and the algorithm was invented by him ~2200 years ago!


The algorithm is based on following easily verifiable observation:
**If a number n is not prime then n will have one or more prime factors in the range `[2,sqrt(n)]`**
```
class Solution {
public:
    int countPrimes(int n)
    {
        if (n<2) return 0;
        vector<bool> prime(n+1,true);
        for (int p=2; p*p<=n; ++p)
        {
            if (!prime[p]) continue;
            for (int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
        
        int ctr = 0;
        for (int p=2; p<n; ++p) ctr += prime[p];
        return ctr;
    }
};
```
If you are wondering about the inner loop why it starts from `p*p` ie we are marking `[p*p, p*p+p, p*p+2p, p*p+3p,..,n]` and so on and why we are not starting from p ie `[p, 2p, 3p,..,n]`, it is because `[p,2p,..,p*p)` will already be marked by some other smaller prime.