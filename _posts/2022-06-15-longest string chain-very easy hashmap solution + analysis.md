---
layout: mypost
title: "Longest String Chain - Very Easy Hashmap solution + Analysis"
tags: ["Array", "Hash Table", "Two Pointers", "String", "Dynamic Programming", "C++", "Medium"]
---
# Problem Statement:
<p>You are given an array of <code>words</code> where each word consists of lowercase English letters.</p>

<p><code>word<sub>A</sub></code> is a <strong>predecessor</strong> of <code>word<sub>B</sub></code> if and only if we can insert <strong>exactly one</strong> letter anywhere in <code>word<sub>A</sub></code> <strong>without changing the order of the other characters</strong> to make it equal to <code>word<sub>B</sub></code>.</p>

<ul>
	<li>For example, <code>&quot;abc&quot;</code> is a <strong>predecessor</strong> of <code>&quot;ab<u>a</u>c&quot;</code>, while <code>&quot;cba&quot;</code> is not a <strong>predecessor</strong> of <code>&quot;bcad&quot;</code>.</li>
</ul>

<p>A <strong>word chain</strong><em> </em>is a sequence of words <code>[word<sub>1</sub>, word<sub>2</sub>, ..., word<sub>k</sub>]</code> with <code>k &gt;= 1</code>, where <code>word<sub>1</sub></code> is a <strong>predecessor</strong> of <code>word<sub>2</sub></code>, <code>word<sub>2</sub></code> is a <strong>predecessor</strong> of <code>word<sub>3</sub></code>, and so on. A single word is trivially a <strong>word chain</strong> with <code>k == 1</code>.</p>

<p>Return <em>the <strong>length</strong> of the <strong>longest possible word chain</strong> with words chosen from the given list of </em><code>words</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;b&quot;,&quot;ba&quot;,&quot;bca&quot;,&quot;bda&quot;,&quot;bdca&quot;]
<strong>Output:</strong> 4
<strong>Explanation</strong>: One of the longest word chains is [&quot;a&quot;,&quot;<u>b</u>a&quot;,&quot;b<u>d</u>a&quot;,&quot;bd<u>c</u>a&quot;].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;xbc&quot;,&quot;pcxbcf&quot;,&quot;xb&quot;,&quot;cxbc&quot;,&quot;pcxbc&quot;]
<strong>Output:</strong> 5
<strong>Explanation:</strong> All the words can be put in a word chain [&quot;xb&quot;, &quot;xb<u>c</u>&quot;, &quot;<u>c</u>xbc&quot;, &quot;<u>p</u>cxbc&quot;, &quot;pcxbc<u>f</u>&quot;].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abcd&quot;,&quot;dbqca&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The trivial word chain [&quot;abcd&quot;] is one of the longest word chains.
[&quot;abcd&quot;,&quot;dbqca&quot;] is not a valid word chain because the ordering of the letters is changed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 16</code></li>
	<li><code>words[i]</code> only consists of lowercase English letters.</li>
</ul>

# Solution:
# Algorithm:
- Sort words by word length in ascending order
- Initialize Hashmap H of type `string->int`
- For each word find subwords (word-1 char) and check if subword is in H. Find the maximum possible value of `H[subword]`  out of all subwords. Call it `ctr`. If there is no subword in H then `ctr=0`
- `H[word] = ctr+1`
- Finally answer is the maximum of all values in `H`.

 {% highlight cpp %} 
bool complen(string s1, string s2)
{
    return s1.length() < s2.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> H;
        int res=0;
        sort(words.begin(), words.end(), complen);
        for (string word: words)
        {
            int wn = word.length(), ctr=0;
            for (int i=0; i<wn; i++)
            {
                string sub = string(word.begin(),word.begin()+i) + 
                             string(word.begin()+i+1, word.end());
                if (H.count(sub)) ctr=max(ctr,H[sub]);
            }
            H[word]=ctr+1;
            res = max(res, H[word]);
        }
        return res;
    }
};
 {% endhighlight %}
 {% highlight cpp %} 
TC: O(N*|S| + N*log(N))
SC: O(N)
 {% endhighlight %}
where `N=#(words)`, `|S|=max length of word`

Reasoning for TC:
`N*|S|` term comes because for each word we are finding all the subwords
`N*log(N)` term comes because we are doing a sorting operation in the beginning

Reasoning for SC:
Size of HashMap is N.

PLEASE UPVOTE.