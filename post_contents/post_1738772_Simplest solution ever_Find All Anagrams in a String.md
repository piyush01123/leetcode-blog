If we look at the frequency map of s or p, we know it is at max of length 26. So why not just match them? Beats 62% of all solutions in c++ with this simple logic.
C++ Version:
```
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        if (ns<np) return {};
        vector<int> H_s(26,0), H_p(26,0);
        for (char ch: p) H_p[ch-"a"]++;
        for (char ch: string(s.begin(),s.begin()+np)) H_s[ch-"a"]++;
        vector<int> res;
        if (H_s==H_p) res.push_back(0);
        for (int i=1; i<=ns-np; i++)
        {
            char ch1 = s[i-1], ch2=s[i+np-1];
            H_s[ch1-"a"]--;
            H_s[ch2-"a"]++;
            if (H_s==H_p) res.push_back(i);
        }
        return res;
    }
};
```
Python version: (python has a `collections.Counter` that you can use to get frrequency map without writing code)
```
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
		if len(s)<len(p) return []
        H_p = collections.Counter(p)
        H_s = collections.Counter(s[:len(p)])
        res = []
        if H_s==H_p:
            res.append(0)
        for i in range(1,len(s)-len(p)+1):
            ch1, ch2 = s[i-1], s[i+len(p)-1]
            H_s[ch1]-=1
            H_s[ch2]+=1
            if H_s==H_p:
                res.append(i)
        return res
```

Complexity: `O(26n)` or in other words `O(n)`