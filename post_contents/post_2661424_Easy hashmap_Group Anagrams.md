Basic idea is to match sorted version of string. Note that anagrams will have same result when sorted. So let us use this as a key for Hashmap.

C++:
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> H;
        for (string str: strs)
        {
            string strsorted = str;
            sort(strsorted.begin(),strsorted.end());
            if (H.count(strsorted))
            {
                H[strsorted].push_back(str);
                continue;
            }
            H[strsorted] = {str};
        }
        vector<vector<string>>res;
        for (auto p: H) res.push_back(p.second);
        return res;
    }
};
```

Python:
```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        H = {}
        for str in strs:
            strsorted = "".join(sorted(str))
            if strsorted in H:
                H[strsorted].append(str)
                continue
            H[strsorted] = [str];
        return list(H.values())
```