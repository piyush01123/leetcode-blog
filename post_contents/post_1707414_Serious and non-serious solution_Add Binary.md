Serious solution:
```
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        while (i>=0 && j>=0)
        {
            int sum = carry + (a[i]-"0") + (b[j]-"0");
            res.push_back("0"+sum%2);
            carry = (sum>1)?1:0;
            i--; j--;
        }
        while (i>=0)
        {
            int sum = carry + (a[i]-"0");
            res.push_back("0"+sum%2);
            carry = (sum>1)?1:0;
            i--;
        }
        while (j>=0)
        {
            int sum = carry + (b[j]-"0");
            res.push_back("0"+sum%2);
            carry = (sum>1)?1:0;
            j--;
        }
        if (carry==1) res.push_back("0"+carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
```

If you want to troll LC:
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a,2)+int(b,2))[2:]
```