We only need to notice that the row number for any character is decided by its modulus wrt $m=2*|s|-2$. This can be easily observed once you notice that the pattern starts repeating after it reaches the top row after one zigzag. Hence $m$ is the length of one zigzag. Next we need to check if each position is coming in the downward phase or the upward phase of zigzag and accordingly update that row.

```
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows==1) return s;
        int m = 2*numRows - 2;
        vector<string> rows(numRows, "");
        for (int i=0; i<s.length(); i++)
        {
            int r = i%m;
            if (r<numRows) rows[r].push_back(s[i]);
            else rows[m-r].push_back(s[i]);
        }
        string res = "";
        for (string r: rows) res+=r;
        return res;
    }
};
```

Time complexity: $O(n)$
