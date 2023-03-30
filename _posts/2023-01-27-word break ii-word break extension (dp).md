---
layout: mypost
title: "Word Break II - Word Break extension (DP)"
tags: ["Array", "Hash Table", "String", "Dynamic Programming", "Backtracking", "Trie", "Memoization", "C++", "Hard"]
---
# Problem Statement:
<p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, add spaces in <code>s</code> to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in <strong>any order</strong>.</p>

<p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsanddog&quot;, wordDict = [&quot;cat&quot;,&quot;cats&quot;,&quot;and&quot;,&quot;sand&quot;,&quot;dog&quot;]
<strong>Output:</strong> [&quot;cats and dog&quot;,&quot;cat sand dog&quot;]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;pineapplepenapple&quot;, wordDict = [&quot;apple&quot;,&quot;pen&quot;,&quot;applepen&quot;,&quot;pine&quot;,&quot;pineapple&quot;]
<strong>Output:</strong> [&quot;pine apple pen apple&quot;,&quot;pineapple pen apple&quot;,&quot;pine applepen apple&quot;]
<strong>Explanation:</strong> Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsandog&quot;, wordDict = [&quot;cats&quot;,&quot;dog&quot;,&quot;sand&quot;,&quot;and&quot;,&quot;cat&quot;]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 10</code></li>
	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
</ul>

# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Intuition is from [Word Break](https://leetcode.com/problems/word-break). Basically we check at each position, if there is a valid word from any previous position. Reproducing my solution for Word Break below:
 {% highlight cpp %} 
bool wordBreak(string s, vector<string>& words) 
{
    unordered_set<string> wordSet(words.begin(),words.end());
    int n = s.length();
    vector<bool> valid(n+1, false);
    valid[0] = true;
    for (int j=1; j<=n; j++)
        for (int i=0; i<j && !valid[j]; i++)
            valid[j] = valid[i] && wordSet.count(s.substr(i,j-i));
    return valid[n];
}
 {% endhighlight %}

# Approach
<!-- Describe your approach to solving the problem. -->
Instead of a 1-D boolean `valid` array, here we will maintain a 2-D string array `A`. `A[i]` will have all valid "sentences" for `s[0:i]`. `A[0]` is a single word sentence (placeholder *). To find `A[j]` we look for all previous `A[i]` for all `i` in `0<=i<j` and if we find any sentence in `A[i]` then `A[j]` will have that sentence added with the word `s.substr(i,j-i)`. Finally we get rid of the placeholder and first space character in each sentence of `A[n]` to get the answer.



# Code
 {% highlight cpp %} 
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& words) 
    {
        unordered_set<string> wordSet(words.begin(),words.end());
        int n = s.length();
        vector<vector<string>> A(n+1,vector<string>{});
        A[0] = {"*"};
        for (int j=1; j<=n; j++)
            for (int i=0; i<j; i++)
                if (A[i].size()>0 && wordSet.count(s.substr(i,j-i)))
                    for (string w: A[i])
                        A[j].push_back(w+" "+s.substr(i,j-i));
        auto res = A[n];
        for (string &s: res) s = s.substr(2);
        return res;
    }
};
 {% endhighlight %}

Related:
https://leetcode.com/problems/concatenated-words/solutions/3106355/