# Sol1: HashSet of int: O(n)

```
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> S;
        int curr = 0, n=s.size(), useful=(1<<(k-1))-1;
        if (n<k) return false;
        for (int i=0; i<k; i++) curr = curr*2 + (s[i]-"0");
        S.insert(curr);
        for (int i=k; i<n; i++)
        {
            curr = curr&useful;
            curr = curr << 1;
            curr = curr + (s[i]-"0");
            S.insert(curr);
        }
        return S.size()==(1<<k);
    }
};
```

# Sol2: HashSet of string: O(nk)
```
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> S;
        int n=s.size();
        for (int i=0; i<n-k+1; i++) S.insert(string(s.begin()+i,s.begin()+i+k));
        return S.size()==(1<<k);
    }
};
```
