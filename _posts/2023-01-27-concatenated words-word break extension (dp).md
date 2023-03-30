---
layout: mypost
title: "Concatenated Words - Word Break extension (DP)"
tags: ["Array", "String", "Dynamic Programming", "Depth-First Search", "Trie", "C++", "Hard"]
---
# Problem Statement:
<p>Given an array of strings <code>words</code> (<strong>without duplicates</strong>), return <em>all the <strong>concatenated words</strong> in the given list of</em> <code>words</code>.</p>

<p>A <strong>concatenated word</strong> is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct)&nbsp;in the given array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cat&quot;,&quot;cats&quot;,&quot;catsdogcats&quot;,&quot;dog&quot;,&quot;dogcatsdog&quot;,&quot;hippopotamuses&quot;,&quot;rat&quot;,&quot;ratcatdogcat&quot;]
<strong>Output:</strong> [&quot;catsdogcats&quot;,&quot;dogcatsdog&quot;,&quot;ratcatdogcat&quot;]
<strong>Explanation:</strong> &quot;catsdogcats&quot; can be concatenated by &quot;cats&quot;, &quot;dog&quot; and &quot;cats&quot;; 
&quot;dogcatsdog&quot; can be concatenated by &quot;dog&quot;, &quot;cats&quot; and &quot;dog&quot;; 
&quot;ratcatdogcat&quot; can be concatenated by &quot;rat&quot;, &quot;cat&quot;, &quot;dog&quot; and &quot;cat&quot;.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cat&quot;,&quot;dog&quot;,&quot;catdog&quot;]
<strong>Output:</strong> [&quot;catdog&quot;]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code> consists of only lowercase English letters.</li>
	<li>All the strings of <code>words</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= sum(words[i].length) &lt;= 10<sup>5</sup></code></li>
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
We just repeat Word Break for each word with all the other words.

# Complexity
- Time complexity: $O(N*M^3)$ where N is size of `words` array and `M` is the length of longest word. $N*M^2$ can be seen clearly from the `for` loops in code below. Extra `M` term is for string hashing.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(N*M)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
 {% highlight cpp %} 
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        unordered_set<string> wordSet(words.begin(),words.end());
        vector<string> res;
        for (string word: words)
        {
            wordSet.erase(word);
            int n = word.length();
            vector<bool> valid(n+1, false);
            valid[0] = true;
            for (int j=1; j<=n; j++)
                for (int i=0; i<j && !valid[j]; i++)
                    valid[j] = valid[i] && wordSet.count(word.substr(i,j-i));
            if (valid[n]) res.push_back(word);
            wordSet.insert(word);
        }
        return res;        
    }
};
 {% endhighlight %}