---
layout: mypost
title: "Partition Labels - Greedy logic"
tags: ["Hash Table", "Two Pointers", "String", "Greedy", "C++", "Medium"]
---
# Problem Statement:
<p>You are given a string <code>s</code>. We want to partition the string into as many parts as possible so that each letter appears in at most one part.</p>

<p>Note that the partition is done so that after concatenating all the parts in order, the resultant string should be <code>s</code>.</p>

<p>Return <em>a list of integers representing the size of these parts</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ababcbacadefegdehijhklij&quot;
<strong>Output:</strong> [9,7,8]
<strong>Explanation:</strong>
The partition is &quot;ababcbaca&quot;, &quot;defegde&quot;, &quot;hijhklij&quot;.
This is a partition so that each letter appears in at most one part.
A partition like &quot;ababcbacadefegde&quot;, &quot;hijhklij&quot; is incorrect, because it splits s into less parts.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;eccbbbbdec&quot;
<strong>Output:</strong> [10]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

# Solution:
From the question, it is clear that we will need the last position where each character appears. For this we create an array `positions` of length 26. Starting from `i=0`, we track the value of this "last position" in variable `end`. Before reaching `end`, if we find a violation ie see a character whose last appearance is after `end` then we update `end`. If we are able to reach `end` then, we just completed a partition. From here we create a new `start` for the next partition and continue the process. In this way we find all the partitions.


 {% highlight cpp %} 
class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.length(), start=-1, end=0;
        vector<int> res, positions(26,-1);
        for(int i=0; i<n; i++) positions[s[i]-'a'] = i;
        for(int i=0; i<n; i++)
        {
            end = max(end, positions[s[i]-'a']);
            if(i==end)
            {
                res.push_back(end-start);
                start=i;
            }
        }
        return res;
    }
};
 {% endhighlight %}

 {% highlight cpp %} 
TC: O(n)
SC: O(n)
 {% endhighlight %}