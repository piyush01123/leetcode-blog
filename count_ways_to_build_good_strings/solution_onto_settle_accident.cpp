class Solution 
{
    int mod = 1e9+7;
    vector<int> memo;
public:
    int util(int len, int zr, int on)
    {
        if(len<0) return 0;
        if (memo[len]!=-1) return memo[len];
        if (len==0) return memo[len]=1;
        return memo[len] = (util(len-zr, zr, on) + util(len-on, zr, on))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        memo = vector<int>(high+1, -1);
        int res = 0;
        for(int i=low; i<=high; i++){res += util(i,zero,one); res%=mod;}
        return res;
    }
};

/*
f(3) = f(2)+f(2)
f(2) = f(1)+f(1)
f(1) = f(0)+f(0)
f(0) = 1
[1,2,4,8]

f(3) = f(2)+f(1)
f(2) = f(1)+f(0)
f(1) = f(0)
f(0) = 1
[1,1,2,3]

f(1L) = f(50k)+f(50k)
f(50k) = f(0) + f(0)
f(0) = 1
[1,2,4]
*/

/*
f(3) = f(2)+f(2)
f(2) = f(1)+f(1)
f(1) = f(0)+f(0)
f(0) = 1
[1,2,4,8]

f(3) = f(2)+f(1)
f(2) = f(1)+f(0)
f(1) = f(0)
f(0) = 1
[1,1,2,3]

f(1L) = f(50k)+f(50k)
f(50k) = f(0) + f(0)
f(0) = 1
[1,2,4]
*/