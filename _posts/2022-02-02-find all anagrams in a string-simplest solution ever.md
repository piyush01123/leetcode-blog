---
layout: mypost
title: "Find All Anagrams in a String - Simplest solution ever"
tags: ["Hash Table", "String", "Sliding Window", "Python", "C", "Medium"]
---
# Problem Statement:
<p>Given two strings <code>s</code> and <code>p</code>, return <em>an array of all the start indices of </em><code>p</code><em>&#39;s anagrams in </em><code>s</code>. You may return the answer in <strong>any order</strong>.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cbaebabacd&quot;, p = &quot;abc&quot;
<strong>Output:</strong> [0,6]
<strong>Explanation:</strong>
The substring with start index = 0 is &quot;cba&quot;, which is an anagram of &quot;abc&quot;.
The substring with start index = 6 is &quot;bac&quot;, which is an anagram of &quot;abc&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abab&quot;, p = &quot;ab&quot;
<strong>Output:</strong> [0,1,2]
<strong>Explanation:</strong>
The substring with start index = 0 is &quot;ab&quot;, which is an anagram of &quot;ab&quot;.
The substring with start index = 1 is &quot;ba&quot;, which is an anagram of &quot;ab&quot;.
The substring with start index = 2 is &quot;ab&quot;, which is an anagram of &quot;ab&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, p.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code> and <code>p</code> consist of lowercase English letters.</li>
</ul>

# Solution:
If we look at the frequency map of s or p, we know it is at max of length 26. So why not just match them? Beats 62% of all solutions in c++ with this simple logic.
C++ Version:
 {% highlight python %} 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np = p.size();
        if (ns<np) return {};
        vector<int> H_s(26,0), H_p(26,0);
        for (char ch: p) H_p[ch-'a']++;
        for (char ch: string(s.begin(),s.begin()+np)) H_s[ch-'a']++;
        vector<int> res;
        if (H_s==H_p) res.push_back(0);
        for (int i=1; i<=ns-np; i++)
        {
            char ch1 = s[i-1], ch2=s[i+np-1];
            H_s[ch1-'a']--;
            H_s[ch2-'a']++;
            if (H_s==H_p) res.push_back(i);
        }
        return res;
    }
};
 {% endhighlight %}
Python version: (python has a `collections.Counter` that you can use to get frrequency map without writing code)
 {% highlight python %} 
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
		if len(s)<len(p) return []
        H_p = collections.Counter(p)
        H_s = collections.Counter(s[:len(p)])
        res = []
        if H_s==H_p:
            res.append(0)
        for i in range(1,len(s)-len(p)+1):
            ch1, ch2 = s[i-1], s[i+len(p)-1]
            H_s[ch1]-=1
            H_s[ch2]+=1
            if H_s==H_p:
                res.append(i)
        return res
 {% endhighlight %}

Complexity: `O(26n)` or in other words `O(n)`