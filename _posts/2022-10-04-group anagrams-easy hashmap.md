---
layout: mypost
title: "Group Anagrams - Easy hashmap"
tags: ["Array", "Hash Table", "String", "Sorting", "C++", "Python", "Medium"]
---
# Problem Statement:
<p>Given an array of strings <code>strs</code>, group <strong>the anagrams</strong> together. You can return the answer in <strong>any order</strong>.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> strs = ["eat","tea","tan","ate","nat","bat"]
<strong>Output:</strong> [["bat"],["nat","tan"],["ate","eat","tea"]]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> strs = [""]
<strong>Output:</strong> [[""]]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> strs = ["a"]
<strong>Output:</strong> [["a"]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code> consists of lowercase English letters.</li>
</ul>

# Solution:
Basic idea is to match sorted version of string. Note that anagrams will have same result when sorted. So let us use this as a key for Hashmap.

C++:
 {% highlight python %} 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> H;
        for (string str: strs)
        {
            string strsorted = str;
            sort(strsorted.begin(),strsorted.end());
            if (H.count(strsorted))
            {
                H[strsorted].push_back(str);
                continue;
            }
            H[strsorted] = {str};
        }
        vector<vector<string>>res;
        for (auto p: H) res.push_back(p.second);
        return res;
    }
};
 {% endhighlight %}

Python:
 {% highlight python %} 
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        H = {}
        for str in strs:
            strsorted = ''.join(sorted(str))
            if strsorted in H:
                H[strsorted].append(str)
                continue
            H[strsorted] = [str];
        return list(H.values())
 {% endhighlight %}