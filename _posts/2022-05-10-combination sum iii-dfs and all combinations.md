---
layout: mypost
title: "Combination Sum III - DFS and All combinations"
tags: ["Array", "Backtracking", "Medium"]
---
# Problem Statement:
<p>Find all valid combinations of <code>k</code> numbers that sum up to <code>n</code> such that the following conditions are true:</p>

<ul>
	<li>Only numbers <code>1</code> through <code>9</code> are used.</li>
	<li>Each number is used <strong>at most once</strong>.</li>
</ul>

<p>Return <em>a list of all possible valid combinations</em>. The list must not contain the same combination twice, and the combinations may be returned in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> [[1,2,4]]
<strong>Explanation:</strong>
1 + 2 + 4 = 7
There are no other valid combinations.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> k = 3, n = 9
<strong>Output:</strong> [[1,2,6],[1,3,5],[2,3,4]]
<strong>Explanation:</strong>
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> k = 4, n = 1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 &gt; 1, there are no valid combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 60</code></li>
</ul>

# Solution:
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