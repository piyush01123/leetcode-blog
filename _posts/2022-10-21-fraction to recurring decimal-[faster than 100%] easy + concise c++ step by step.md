---
layout: mypost
title: "Fraction to Recurring Decimal - [Faster than 100%] Easy + Concise C++ Step by step"
tags: ["Hash Table", "Math", "String", "Medium"]
---
# Problem Statement:
<p>Given two integers representing the <code>numerator</code> and <code>denominator</code> of a fraction, return <em>the fraction in string format</em>.</p>

<p>If the fractional part is repeating, enclose the repeating part in parentheses.</p>

<p>If multiple answers are possible, return <strong>any of them</strong>.</p>

<p>It is <strong>guaranteed</strong> that the length of the answer string is less than <code>10<sup>4</sup></code> for all the given inputs.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> numerator = 1, denominator = 2
<strong>Output:</strong> &quot;0.5&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> numerator = 2, denominator = 1
<strong>Output:</strong> &quot;2&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> numerator = 4, denominator = 333
<strong>Output:</strong> &quot;0.(012)&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;=&nbsp;numerator, denominator &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>denominator != 0</code></li>
</ul>

# Solution:
Here is the code without taking care of the recurring decimal (Will give you WA for case `nr=1,dr=3` but still it is useful to understand):
```
string fractionToDecimal(int nr, int dr) 
{
	if (nr==0) return "0";
	string res = "";
	if ((nr<0)^(dr<0)) res += '-';
	nr = abs(nr), dr=abs(dr);
	res += to_string(nr/dr);
	int rem = nr%dr;
	if (rem==0) return res;
	res += '.';
	while (rem>0)
	{
		rem *= 10;
		res += to_string(rem/dr);
		rem %= dr;
	}
	return res;
}
```

Now we add the recurring decimal part. We will use a hash map to store the position of each decimal digit. If we have seen it earlier than we are due to repeat, hence we break and return.

There are some gotchas you need to take care of.
- `abs(INT_MIN)` is `INT_MIN` as defined in `cstdlib.h`.
- Hence we use `long long int` for our nr and dr.
- Also use `long long int` for the remainder.
- You got to be careful about the insertion position of the starting open paranthesis `(`.

Final code:
```
string fractionToDecimal(long long nr, long long dr) 
{
    if (nr==0) return "0";
    string res = "";
    if ((nr<0)^(dr<0)) res += '-';
    nr = abs(nr), dr=abs(dr);
    res += to_string(nr/dr);
    long long rem = nr%dr;
    if (rem==0) return res;
    res += '.';
    unordered_map<int,int> decimal;
    while (rem>0 && decimal.count(rem)==0)
    {
        decimal[rem] = res.length();
        rem *= 10;
        res += to_string(rem/dr);
        rem %= dr;
    }
    if (rem>0)
    {
        res.insert(decimal[rem], "(");
        res += ')';
    }
    return res;
}
```

**Result:**
```
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fraction to Recurring Decimal.
Memory Usage: 6.3 MB, less than 74.68% of C++ online submissions for Fraction to Recurring Decimal.
```