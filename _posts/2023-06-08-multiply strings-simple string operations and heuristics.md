---
layout: mypost
title: "Multiply Strings - Simple string operations and heuristics"
tags: ["Math", "String", "Simulation", "C++", "Medium"]
---
# Problem Statement:
<p>Given two non-negative integers <code>num1</code> and <code>num2</code> represented as strings, return the product of <code>num1</code> and <code>num2</code>, also represented as a string.</p>

<p><strong>Note:</strong>&nbsp;You must not use any built-in BigInteger library or convert the inputs to integer directly.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num1 = "2", num2 = "3"
<strong>Output:</strong> "6"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num1 = "123", num2 = "456"
<strong>Output:</strong> "56088"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 200</code></li>
	<li><code>num1</code> and <code>num2</code> consist of digits only.</li>
	<li>Both <code>num1</code> and <code>num2</code>&nbsp;do not contain any leading zero, except the number <code>0</code> itself.</li>
</ul>

# Solution:
We will use several heuristics for this problem:
- Given two string numbers to multiply, we can treat one input as the *multiplicator* and another as *multiplicand*. We go over the *multiplicator* digit by digit from left to right and get the product of each digit with the *multiplicand* using a function *digitMul* that we will create. Once we get the output of *digitMul*, we add zeroes at the end of the output. The number of zeroes is equal to the place value of the digit inside *multiplicator*.
- You must have guessed that if we simply add the outputs of the above operation, we can get the answer. So we create a function *add* to add two string numbers.
- Now we need to write the logic of *add* and *digitMul*. To write *add* and *digitMul* functions, we can do it simply like how we learnt in kindergarten. 

 {% highlight cpp %} 
class Solution {
public:
    string add(string a, string b)
    {
        if (!a.length()) return b;
        if (!b.length()) return a;
        string res = "";
        int carry = 0;
        while(a.length() && b.length())
        {
            int cur = (a.back()-'0')+(b.back()-'0')+carry;
            res += to_string(cur%10);
            carry = cur/10;
            a.pop_back();
            b.pop_back();
        }
        while(a.length())
        {
            int cur = (a.back()-'0')+carry;
            res += to_string(cur%10);
            carry = cur/10;
            a.pop_back();
        }
        while(b.length())
        {
            int cur = (b.back()-'0')+carry;
            res += to_string(cur%10);
            carry = cur/10;
            b.pop_back();
        }
        if (carry) res += to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
    string digitMul(int a, string num)
    {
        string res = "";
        int carry = 0;
        for (int i=num.size()-1; i>=0; i--)
        {
            int cur = a * (num[i]-'0') + carry;
            res.push_back('0' + (cur%10));
            carry = (cur/10);
        }
        if (carry) res.push_back('0'+carry);
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) 
    {
        if (num1=="0" || num2=="0") return "0";
        string result = "";
        for (int i=0; i<num1.length(); i++)
        {
            string product = digitMul(num1[i]-'0', num2);
            product += string(num1.length()-i-1, '0');
            result = add(result, product);
        }
        return result;
    }
};
 {% endhighlight %}