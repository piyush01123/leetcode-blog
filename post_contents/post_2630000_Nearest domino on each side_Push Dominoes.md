Consider example
```
".L.R...LR..L.."
```
Now any domino which is pushed at t = 0 will remain as it is and we only need to worry about the standing ones (dots).
Now a domino falls towards right if the nearest non-dot domino in the left side is pushed rightwards. (Situation A). This means the pattern `R....`
And a domino falls towards left if the nearest non-dot domino in the right side is pushed leftwards. (Situation B). This means the pattern `...L`

**How do we do this?**
Create a data structure `nearest_left` which denotes for any dot, the nearest non-dot character in its left side along with the distance from itself.
```
0: NULL
2: (L,1)
4: (R,1)
5: (R,2)
6: (R,3)
9: (R,1)
10: (R,2)
12: (L,1)
13: (L,2)
```
Similarly we have `nearest_right`.
```
0: (L,1)
2: (R,1)
4: (L,3)
5: (L,2)
6: (L,1)
9: (L,2)
10: (L,1)
12: NULL
13: NULL
```

Now situation A means `nearest_left` for that dot is a `R` and situation B means `nearest_right` for that dot is a `L`.

Now for any dot we can have:
- Neither A nor B ==> Remains standing
- A only ==> falls towards right
-  B only ==> falls toward left
- Both A and B. In this case the direction of fall is decided by the nearer of the two. Remain standing if distances same.

For our example: 
```
0: B only
2: Neither A nor B
4: Both A and B, A wins
5: Both A and B, Tie.
6: Both A and B, B wins
9: Both A and B, A wins
10: Both A and B, B wins
12: Neither A nor B
13: Neither A nor B
```

This gives us the answer:
```
"LL.RR.LLRRLL.."
```



Now let us implement this logic
```
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<pair<int,pair<char,int>>> nearest_left, nearest_right;
        int left_idx=-1;
        char left_ch="X";
        for (int i=0; i<n; i++)
        {
            if (dominoes[i]!=".")
            {
                left_idx = i;
                left_ch = dominoes[i];
            }
            if (dominoes[i]==".")
                nearest_left.push_back({i,{left_ch,i-left_idx}});
        }
        int right_idx=n;
        char right_ch="X";
        for (int i=n-1; i>=0; i--)
        {
            if (dominoes[i]!=".")
            {
                right_idx = i;
                right_ch = dominoes[i];
            }
            if (dominoes[i]==".")
                nearest_right.push_back({i,{right_ch,right_idx-i}});
        }
        reverse(nearest_right.begin(),nearest_right.end());
        for (int i=0; i<nearest_left.size(); i++)
        {
            auto nl = nearest_left[i], nr = nearest_right[i];
            int dom_idx = nl.first; // this wil be same as nr.first
            auto nls = nl.second, nrs = nr.second;
            if (nls.first=="R" && nrs.first=="L")
            {
                if (nls.second<nrs.second) dominoes[dom_idx] = "R";
                if (nrs.second<nls.second) dominoes[dom_idx] = "L";
                continue;
            }
            if (nls.first=="R")
            {
                dominoes[dom_idx] = "R";
                continue;
            }    
            if (nrs.first=="L") 
            {
                dominoes[dom_idx] = "L";
                continue;
            }
        }
        return dominoes;
    }
};
```