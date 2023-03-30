---
layout: mypost
title: "Partition Labels - Greedy Solution"
tags: ["Hash Table", "Two Pointers", "String", "Greedy", "Medium"]
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
Notice that it is sufficient if you get the first partition. Because the rest of the partitions can be obtained by recursively calling the same function for the remaining part of string.

Here is the code to print the first parition (this is not the solution but this code will help you to understand).
```
vector<int> partitionLabels(string s) 
{
	int n=s.length(), j=n-1;
	while (s[j]!=s[0]) j--;
	for (int i=0; i<=j; i++)
	{
		int jj=n-1;
		while (s[jj]!=s[i]) jj--;
		j = max(j,jj);
	}
	cout << s.substr(0,j+1) << endl;
	return {};
}
```
For `s = ababcbacadefegdehijhklij`, it will print `ababcbaca`
For `s = defegdehijhklij` it will print `defegde`.
For `s = hijhklij` it will print `hijhklij` (same as s).

The way it works is that for each character in the partition we find the maximum index of its occurence. Then the paritition is equal to the maximum of these max-indexes.

Now we just need to find the remaining partitions uising recursion for the remaining part of string.

C++ code:

```
class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> res;
        int n=s.length(), j=n-1;
        while (s[j]!=s[0]) j--;
        for (int i=0; i<=j; i++)
        {
            int jj=n-1;
            while (s[jj]!=s[i]) jj--;
            j = max(j,jj);
        }
        res.push_back(j+1);
        if (j<s.length()-1)
        {
            for (int len: partitionLabels(s.substr(j+1,n)))
                res.push_back(len);
        }
        return res;
    }
};
```