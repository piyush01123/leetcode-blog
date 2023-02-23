We can do DFS and check for current sum. If meets the condition add to result.
C++ solution:
```
class Solution {
public:
    void combn(int curr, int target, int count,  vector<vector<int>> &res, vector<int> &v)
    {
        if (count<0 || target<0) return;
        if (count==0 && target==0)
        {
            res.push_back(v);
            return;
        }
        for (int i=curr; i<=9; i++)
        {
            v.push_back(i);
            combn(i+1, target-i, count-1, res, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int>v;
        combn(1,n,k,res,v);
        return res;
    }
};
```
We can also do all combinations and get an AC:
Python solution:
```
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        for cb in combinations(range(1,10),k):
            if sum(cb)==n:
                res.append(list(cb))
        return res
```