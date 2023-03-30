---
layout: mypost
title: "Letter Combinations of a Phone Number - Iterative solution"
tags: ["Hash Table", "String", "Backtracking", "C++", "Python", "Medium"]
---
# Problem Statement:
<p>Given a string containing digits from <code>2-9</code> inclusive, return all possible letter combinations that the number could represent. Return the answer in <strong>any order</strong>.</p>

<p>A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png" style="width: 300px; height: 243px;" />
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> digits = &quot;23&quot;
<strong>Output:</strong> [&quot;ad&quot;,&quot;ae&quot;,&quot;af&quot;,&quot;bd&quot;,&quot;be&quot;,&quot;bf&quot;,&quot;cd&quot;,&quot;ce&quot;,&quot;cf&quot;]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> digits = &quot;&quot;
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> digits = &quot;2&quot;
<strong>Output:</strong> [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= digits.length &lt;= 4</code></li>
	<li><code>digits[i]</code> is a digit in the range <code>[&#39;2&#39;, &#39;9&#39;]</code>.</li>
</ul>

# Solution:
# Method:
Create a string array. In the beginning it has only one member which is empty string. Then when you see a digit, create a new array which is each member of old array plus each letter of new digit. Then replace the old array with the new one. Then go to next digit and so on.
Example:
Input: "23"
Array in the process:
 {% highlight python %} 
start=> [""]
digit='2'=> ["a", "b", "c"]
digit='3'=> ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
 {% endhighlight %}

c++:
 {% highlight python %} 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        unordered_map<char,vector<char>> mapping;
        mapping['2']={'a','b','c'};
        mapping['3']={'d','e','f'};
        mapping['4']={'g','h','i'};
        mapping['5']={'j','k','l'};
        mapping['6']={'m','n','o'};
        mapping['7']={'p','q','r','s'};
        mapping['8']={'t','u','v'};
        mapping['9']={'w','x','y','z'};
        vector<string>words {""};
        for (char digit: digits)
        {
            vector<string> new_words;
            for (string word: words)
                for (char letter: mapping[digit])
                    new_words.push_back(word+letter);
            words=new_words;
        }
        return words;
    }
};
 {% endhighlight %}

python:
 {% highlight python %} 
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0: return []
        mapping = {'2': 'abc', '3': 'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        words = [""]
        for digit in digits:
            letters = mapping[digit]
            new_words = []
            for word in words:
                for letter in letters:
                    new_words.append(word+letter)
            words = new_words
        return words
 {% endhighlight %}