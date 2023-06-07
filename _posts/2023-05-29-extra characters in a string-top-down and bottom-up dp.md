---
layout: mypost
title: "Extra Characters in a String - Top-down and Bottom-up DP"
tags: ["Array", "Hash Table", "String", "Dynamic Programming", "Trie", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> string <code>s</code> and a dictionary of words <code>dictionary</code>. You have to break <code>s</code> into one or more <strong>non-overlapping</strong> substrings such that each substring is present in <code>dictionary</code>. There may be some <strong>extra characters</strong> in <code>s</code> which are not present in any of the substrings.</p>

<p>Return <em>the <strong>minimum</strong> number of extra characters left over if you break up </em><code>s</code><em> optimally.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;leetscode&quot;, dictionary = [&quot;leet&quot;,&quot;code&quot;,&quot;leetcode&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can break s in two substrings: &quot;leet&quot; from index 0 to 3 and &quot;code&quot; from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;sayhelloworld&quot;, dictionary = [&quot;hello&quot;,&quot;world&quot;]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can break s in two substrings: &quot;hello&quot; from index 3 to 7 and &quot;world&quot; from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 50</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 50</code></li>
	<li><code>dictionary[i]</code>&nbsp;and <code>s</code> consists of only lowercase English letters</li>
	<li><code>dictionary</code> contains distinct words</li>
</ul>

# Solution:
Let us think through a basic solution. Here is the logic:
- The largest possible answer is length of string. This is the case where we just add 1 for all values till we reach end.
- `1+dfs(s,index+1)` denotes that we have skipped current index and looking for answer starting from next index.
- We have a chance of getting lower value if we check set membership for each substring starting from current index. This is the basic idea. 

I will provide 3 solutions using above logic. I have kept the variable names same to ease understanding things better.


**Naive recursion**(TLE)
 {% highlight cpp %} 
class Solution {
    unordered_set<string> dictSet;
public:
    int dfs(string s, int index)
    {
        if (index>=s.length()) return 0;
        int res = 1 + dfs(s, index+1);
        for (int len=1; len<=s.length()-index;len++)
            if (dictSet.count(s.substr(index,len)))
                    res = min(res, dfs(s, index+len));
        return res;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        dictSet = unordered_set<string>(dictionary.begin(),dictionary.end());
        return dfs(s,0);
    }
};
 {% endhighlight %}

**Recursion with memoization** (AC)
 {% highlight cpp %} 
class Solution {
    unordered_set<string> dictSet;
    vector<int> memo;
public:
    int dfs(string s, int index)
    {
        if (index>=s.length()) return 0;
        if (memo[index]!=-1) return memo[index];
        int res = 1 + dfs(s, index+1);
        for (int len=1; len<=s.length()-index;len++)
            if (dictSet.count(s.substr(index,len)))
                    res = min(res, dfs(s, index+len));
        return memo[index] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        dictSet = unordered_set<string>(dictionary.begin(),dictionary.end());
        memo = vector<int>(s.length()+1,-1);
        return dfs(s,0);
    }
};
 {% endhighlight %}

**Bottom-up DP** (AC)
 {% highlight cpp %} 
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_set<string> dictSet = unordered_set<string>(dictionary.begin(),dictionary.end());
        vector<int> dp(s.length()+1,0);
        for(int index=s.length()-1; index>=0; index--)
        {
            dp[index] = 1 + dp[index+1];
            for (int len=1; len<=s.length()-index; len++)
                if (dictSet.count(s.substr(index,len)))
                    dp[index] = min(dp[index], dp[index+len]);
        }
        return dp[0];
    }
};
 {% endhighlight %}