**How do you add 1 to a binary string**
A: Go from right to left, if you see a one, make it zero. If you see a zero, make it one and stop. If you could not find zero then create a string like `1000` for `111`.

**How do you divide a binary string by 2**
A: Just right shift by  1.

Now that we have both of these pieces, we can simulate the steps:


```
string add_one(string s, int l)
{
    int i=l-1;
    while (i>=0 && s[i]!="0")
    {
        s[i]="0";
        i--;
    }
    if (i>=0) s[i]="1";
    else s="1"+s;
    return s;
}

string divide_by_two(string s)
{
    return string(s.begin(), s.end()-1);
}

class Solution {
public:
    int numSteps(string s) {
        int ctr=0;
        while (s!="1")
        {
            int l = s.length();
            if (s[l-1]=="0") s = divide_by_two(s);
            else s = add_one(s, l);
            ctr ++;
        }
        return ctr;
    }
};
```