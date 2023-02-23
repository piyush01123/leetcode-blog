```
class Solution {
public:
    int countVowelStrings(int n) {
        int a=1, b=1, c=1, d=1, e=1;
        for (int i=2; i<=n; i++)
        {
            d+=e;
            c+=d;
            b+=c;
            a+=b;
        }
        return a+b+c+d+e;
    }
};
```