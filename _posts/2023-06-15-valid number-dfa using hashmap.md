---
layout: mypost
title: "Valid Number - DFA using hashmap"
tags: ["String", "C++", "Hash Table", "Hard"]
---
# Problem Statement:
<p>A <strong>valid number</strong> can be split up into these components (in order):</p>

<ol>
	<li>A <strong>decimal number</strong> or an <strong>integer</strong>.</li>
	<li>(Optional) An <code>&#39;e&#39;</code> or <code>&#39;E&#39;</code>, followed by an <strong>integer</strong>.</li>
</ol>

<p>A <strong>decimal number</strong> can be split up into these components (in order):</p>

<ol>
	<li>(Optional) A sign character (either <code>&#39;+&#39;</code> or <code>&#39;-&#39;</code>).</li>
	<li>One of the following formats:
	<ol>
		<li>One or more digits, followed by a dot <code>&#39;.&#39;</code>.</li>
		<li>One or more digits, followed by a dot <code>&#39;.&#39;</code>, followed by one or more digits.</li>
		<li>A dot <code>&#39;.&#39;</code>, followed by one or more digits.</li>
	</ol>
	</li>
</ol>

<p>An <strong>integer</strong> can be split up into these components (in order):</p>

<ol>
	<li>(Optional) A sign character (either <code>&#39;+&#39;</code> or <code>&#39;-&#39;</code>).</li>
	<li>One or more digits.</li>
</ol>

<p>For example, all the following are valid numbers: <code>[&quot;2&quot;, &quot;0089&quot;, &quot;-0.1&quot;, &quot;+3.14&quot;, &quot;4.&quot;, &quot;-.9&quot;, &quot;2e10&quot;, &quot;-90E3&quot;, &quot;3e+7&quot;, &quot;+6e-1&quot;, &quot;53.5e93&quot;, &quot;-123.456e789&quot;]</code>, while the following are not valid numbers: <code>[&quot;abc&quot;, &quot;1a&quot;, &quot;1e&quot;, &quot;e3&quot;, &quot;99e2.5&quot;, &quot;--6&quot;, &quot;-+3&quot;, &quot;95a54e53&quot;]</code>.</p>

<p>Given a string <code>s</code>, return <code>true</code><em> if </em><code>s</code><em> is a <strong>valid number</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0&quot;
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;e&quot;
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;.&quot;
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> consists of only English letters (both uppercase and lowercase), digits (<code>0-9</code>), plus <code>&#39;+&#39;</code>, minus <code>&#39;-&#39;</code>, or dot <code>&#39;.&#39;</code>.</li>
</ul>

# Solution:
Based on the problem statement, we construct the following DFA (deterministic finite automata) which is basically a state graph. If the input follows the state graph, it is  a valid number.

![WhatsApp Image 2023-06-09 at 14.24.12.jpeg](https://assets.leetcode.com/users/images/81930700-ebc5-4721-8d46-8bd823040d8f_1686300939.1721973.jpeg)

The starting node is A and and the terminal nodes are double encircled.



For coding the solution, we use the same node names as given in the diagram. Edges can be either `dig` for digit, `dot` for dot, `sig` for sign and `exp` for small and capital E. 
 {% highlight cpp %} 
class Solution {
public:
    bool isNumber(string s) 
    {   
        unordered_map<char, unordered_map<string,char>> stateMap;
        stateMap['A'] = { {"dig",'B'}, {"dot",'C'}, {"sig",'D'} };
        stateMap['B'] = { {"dig",'B'}, {"dot",'E'}, {"exp",'F'} };
        stateMap['C'] = { {"dig",'E'} };
        stateMap['D'] = { {"dot",'C'}, {"dig",'B'} };
        stateMap['E'] = { {"dig",'E'}, {"exp",'F'} };
        stateMap['F'] = { {"dig",'G'}, {"sig",'H'} };
        stateMap['G'] = { {"dig",'G'} };
        stateMap['H'] = { {"dig",'G'} };
        char cur = 'A';
        for (char ch: s)
        {
            string state;
            if (ch>='0' && ch<='9') state="dig";
            else if (ch=='+' || ch=='-') state="sig";
            else if (ch=='e' || ch=='E') state ="exp";
            else if (ch=='.') state="dot";
            else return false;
            if (!stateMap[cur].count(state)) return false;
            cur = stateMap[cur][state];
        }
        return (cur=='B' || cur=='E' || cur=='G');
    }
};

 {% endhighlight %}

If you are interested, I am adding code to run some tests:
 {% highlight cpp %} 
class Solution {
public:
    bool isNumberUtil(string s)
    {
        unordered_map<char, unordered_map<string,char>> stateMap;
        stateMap['A'] = { {"dig",'B'}, {"dot",'C'}, {"sig",'D'} };
        stateMap['B'] = { {"dig",'B'}, {"dot",'E'}, {"exp",'F'} };
        stateMap['C'] = { {"dig",'E'} };
        stateMap['D'] = { {"dot",'C'}, {"dig",'B'} };
        stateMap['E'] = { {"dig",'E'}, {"exp",'F'} };
        stateMap['F'] = { {"dig",'G'}, {"sig",'H'} };
        stateMap['G'] = { {"dig",'G'} };
        stateMap['H'] = { {"dig",'G'} };
        char cur = 'A';
        for (char ch: s)
        {
            string state;
            if (ch>='0' && ch<='9') state="dig";
            else if (ch=='+' || ch=='-') state="sig";
            else if (ch=='e' || ch=='E') state ="exp";
            else if (ch=='.') state="dot";
            else return false;
            if (!stateMap[cur].count(state)) return false;
            cur = stateMap[cur][state];
        }
        return (cur=='B' || cur=='E' || cur=='G');
    }

    void runTests()
    {
        vector<string> tests{"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};
        for(string test: tests) cout<<test<<' '<< (isNumberUtil(test)?"TRUE":"FALSE" )<< endl;
    }

    bool isNumber(string s) 
    {   
        runTests();
        return isNumberUtil(s);
    }
};
 {% endhighlight %}

You can see that all  outputs are as expected.
 {% highlight cpp %} 
2 TRUE
0089 TRUE
-0.1 TRUE
+3.14 TRUE
4. TRUE
-.9 TRUE
2e10 TRUE
-90E3 TRUE
3e+7 TRUE
+6e-1 TRUE
53.5e93 TRUE
-123.456e789 TRUE
abc FALSE
1a FALSE
1e FALSE
e3 FALSE
99e2.5 FALSE
--6 FALSE
-+3 FALSE
95a54e53 FALSE
 {% endhighlight %}