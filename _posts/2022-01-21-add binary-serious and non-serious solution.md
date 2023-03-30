---
layout: mypost
title: "Add Binary - Serious and non-serious solution"
tags: ["Math", "String", "Bit Manipulation", "Simulation", "Easy"]
---
# Problem Statement:
<p>Given two binary strings <code>a</code> and <code>b</code>, return <em>their sum as a binary string</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> a = "11", b = "1"
<strong>Output:</strong> "100"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> a = "1010", b = "1011"
<strong>Output:</strong> "10101"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code> and <code>b</code> consist&nbsp;only of <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code> characters.</li>
	<li>Each string does not contain leading zeros except for the zero itself.</li>
</ul>

# Solution:
Serious solution:
```
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        while (i>=0 && j>=0)
        {
            int sum = carry + (a[i]-'0') + (b[j]-'0');
            res.push_back('0'+sum%2);
            carry = (sum>1)?1:0;
            i--; j--;
        }
        while (i>=0)
        {
            int sum = carry + (a[i]-'0');
            res.push_back('0'+sum%2);
            carry = (sum>1)?1:0;
            i--;
        }
        while (j>=0)
        {
            int sum = carry + (b[j]-'0');
            res.push_back('0'+sum%2);
            carry = (sum>1)?1:0;
            j--;
        }
        if (carry==1) res.push_back('0'+carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
```

If you want to troll LC:
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a,2)+int(b,2))[2:]
```