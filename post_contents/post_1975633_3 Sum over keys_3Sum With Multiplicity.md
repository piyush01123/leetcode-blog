```
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size(), MAX=101, res=0, MOD=1000000007;
        vector<int> frequencies(MAX, 0);
        for (int k: arr) frequencies[k]++;
        for (int x=0; x<MAX; x++)
        {
            for (int y=x+1; y<MAX; y++)
            {
                int z=target-x-y;
                if (z>y && z<MAX)
                {
                    long long a=frequencies[x], b=frequencies[y], c=frequencies[z];
                    long long d = a*b*c;
                    res += d%MOD;
                    res %= MOD;
                }
            }
        }
        for (int x=0; x<MAX; x++)
        {
            int y = target-2*x; //x,x,y
            if (y>x && y<MAX)
            {
                long long a=frequencies[x], b=frequencies[y];
                long long c = b * a * (a-1)/2;
                res += c%MOD;
                res %= MOD;
            }
        }
        for (int x=0; x<MAX; x++)
        {
            int y = (target-x)/2; // x,y,y
            if (y>x && (target-x)%2==0 && y<MAX)
            {
                long long a=frequencies[x], b=frequencies[y];
                long long c = a * b * (b-1)/2;
                res += c%MOD;
                res %= MOD;
            }
        }
        if (target%3==0)
        {
            int x=target/3;
            long long a=frequencies[x];
            long long b = a * (a-1) * (a-2)/6;
            res += b%MOD;
            res %= MOD;
        }
        return res;
    }
};
```

```
TC: O(MAX^2)
SC: O(MAX)
```
where `MAX` is the maximum value in the array (here 100).
Notice that the complexities do not depend on the length of `arr`.