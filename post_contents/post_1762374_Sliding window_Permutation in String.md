# Algorithm
- Create an array of size 26 storing letter frequencis of  `s1`.
- Similarly do it for `s2` but just upto `n1` where `n1=s1.size()`
- Slide winow in `s2` and add the upcoming letter and subtract the outgoing letter
- If the frequency table matches return True
- Finally return false if it never matched


```
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        if (n1>n2) return false;
        vector<int> v1(26,0), v2(26,0);
        for (char ch: s1) v1[ch-"a"]++;
        for (int i=0; i<n2; i++)
        {
            v2[s2[i]-"a"]++;
            if (i>=n1) v2[s2[i-n1]-"a"]--;
            if (v1==v2) return true;
        }
        return false;
    }
};
```