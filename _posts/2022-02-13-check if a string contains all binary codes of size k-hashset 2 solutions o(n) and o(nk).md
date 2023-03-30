---
layout: mypost
title: "Check If a String Contains All Binary Codes of Size K - HashSet 2 solutions O(n) and O(nk)"
tags: ["Hash Table", "String", "Bit Manipulation", "Rolling Hash", "Hash Function", "C++", "Medium"]
---
# Problem Statement:
<p>Given a binary string <code>s</code> and an integer <code>k</code>, return <code>true</code> <em>if every binary code of length</em> <code>k</code> <em>is a substring of</em> <code>s</code>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;00110110&quot;, k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> The binary codes of length 2 are &quot;00&quot;, &quot;01&quot;, &quot;10&quot; and &quot;11&quot;. They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0110&quot;, k = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> The binary codes of length 1 are &quot;0&quot; and &quot;1&quot;, it is clear that both exist as a substring. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0110&quot;, k = 2
<strong>Output:</strong> false
<strong>Explanation:</strong> The binary code &quot;00&quot; is of length 2 and does not exist in the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
	<li><code>1 &lt;= k &lt;= 20</code></li>
</ul>

# Solution:
# Sol1: HashSet of int: O(n)

 {% highlight cpp %} 
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> S;
        int curr = 0, n=s.size(), useful=(1<<(k-1))-1;
        if (n<k) return false;
        for (int i=0; i<k; i++) curr = curr*2 + (s[i]-'0');
        S.insert(curr);
        for (int i=k; i<n; i++)
        {
            curr = curr&useful;
            curr = curr << 1;
            curr = curr + (s[i]-'0');
            S.insert(curr);
        }
        return S.size()==(1<<k);
    }
};
 {% endhighlight %}

# Sol2: HashSet of string: O(nk)
 {% highlight cpp %} 
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> S;
        int n=s.size();
        for (int i=0; i<n-k+1; i++) S.insert(string(s.begin()+i,s.begin()+i+k));
        return S.size()==(1<<k);
    }
};
 {% endhighlight %}
