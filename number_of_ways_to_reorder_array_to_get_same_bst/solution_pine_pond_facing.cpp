class Solution {
    int mod=1e9+7;
    vector<long long> answers;
public:
    void nCr(int n, int r)
    {
        int ro=r, no=n;
        long long p = 1, k = 1;
        if (n - r < r) r = n - r;
        if (r == 0) return;
        while (r) 
        {
            p *= n; k *= r;
            long long m = __gcd(p, k);
            p /= m; k /= m;
            n--; r--;
            p%=mod; k%=mod;
        }
        cout<<"NCR:"<<no<<','<<ro<<','<<p<<endl;
        answers.push_back(p);
    }

    /* Iterative Function to calculate (x^y)%p in O(log y) */
    unsigned long long power(unsigned long long x,int y, int p)
    {
        unsigned long long res = 1; // Initialize result
        x = x % p; // Update x if it is more than or
        // equal to p
        while (y > 0)
        {        
            // If y is odd, multiply x with result
            if (y & 1) res = (res * x) % p;
            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
        return res;
    }

    // Returns n^(-1) mod p
    unsigned long long modInverse(unsigned long long n, int p)
    {
        return power(n, p - 2, p);
    }
    void nCrModPFermat(unsigned long long n, int r, int p)
    {
        if (n - r < r) r = n - r;
        if (r == 0) return;
        unsigned long long fac[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
        unsigned long long res = (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)  %  p;
        answers.push_back(res);
    }

    void numOfWaysUtil(vector<int>& nums) 
    {
        if (nums.size()<=2) return;
        vector<int>left, right;
        for(int i=1; i<nums.size(); i++)
            if(nums[i]<nums[0]) left.push_back(nums[i]); else right.push_back(nums[i]);
        nCrModPFermat(nums.size()-1, left.size(), mod);
        numOfWaysUtil(left);
        numOfWaysUtil(right);
    }
    int numOfWays(vector<int>& nums) 
    {
        numOfWaysUtil(nums);
        long long res=1;
        for(long long item: answers) {res *= item%mod; res%=mod;}
        return res-1;
    }
};

/*
10,
16,18,13,11,12,15,17,14
1,8,7,5,9,2,3,6,4,
*/

/*
   n!
--------
r!(n-r)!

r+1 * r+2 + .. n
----------------
1 * 2 * n-r
*/