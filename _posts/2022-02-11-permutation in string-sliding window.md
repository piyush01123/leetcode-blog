---
layout: mypost
title: "Permutation in String - Sliding window"
tags: ["Hash Table", "Two Pointers", "String", "Sliding Window", "C++", "Medium"]
---
# Problem Statement:
<p>Given two strings <code>s1</code> and <code>s2</code>, return <code>true</code><em> if </em><code>s2</code><em> contains a permutation of </em><code>s1</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>In other words, return <code>true</code> if one of <code>s1</code>&#39;s permutations is the substring of <code>s2</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;ab&quot;, s2 = &quot;eidbaooo&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> s2 contains one permutation of s1 (&quot;ba&quot;).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;ab&quot;, s2 = &quot;eidboaoo&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
</ul>

# Solution:
# Algorithm
- Create an array of size 26 storing letter frequencis of  `s1`.
- Similarly do it for `s2` but just upto `n1` where `n1=s1.size()`
- Slide winow in `s2` and add the upcoming letter and subtract the outgoing letter
- If the frequency table matches return True
- Finally return false if it never matched


 {% highlight cpp %} 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        if (n1>n2) return false;
        vector<int> v1(26,0), v2(26,0);
        for (char ch: s1) v1[ch-'a']++;
        for (int i=0; i<n2; i++)
        {
            v2[s2[i]-'a']++;
            if (i>=n1) v2[s2[i-n1]-'a']--;
            if (v1==v2) return true;
        }
        return false;
    }
};
 {% endhighlight %}