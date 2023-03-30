---
layout: mypost
title: "Naming a Company - HashSet for all letters"
tags: ["Array", "Hash Table", "String", "Bit Manipulation", "Enumeration", "C++", "Hard"]
---
# Problem Statement:
<p>You are given an array of strings <code>ideas</code> that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:</p>

<ol>
	<li>Choose 2 <strong>distinct</strong> names from <code>ideas</code>, call them <code>idea<sub>A</sub></code> and <code>idea<sub>B</sub></code>.</li>
	<li>Swap the first letters of <code>idea<sub>A</sub></code> and <code>idea<sub>B</sub></code> with each other.</li>
	<li>If <strong>both</strong> of the new names are not found in the original <code>ideas</code>, then the name <code>idea<sub>A</sub> idea<sub>B</sub></code> (the <strong>concatenation</strong> of <code>idea<sub>A</sub></code> and <code>idea<sub>B</sub></code>, separated by a space) is a valid company name.</li>
	<li>Otherwise, it is not a valid name.</li>
</ol>

<p>Return <em>the number of <strong>distinct</strong> valid names for the company</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> ideas = [&quot;coffee&quot;,&quot;donuts&quot;,&quot;time&quot;,&quot;toffee&quot;]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The following selections are valid:
- (&quot;coffee&quot;, &quot;donuts&quot;): The company name created is &quot;doffee conuts&quot;.
- (&quot;donuts&quot;, &quot;coffee&quot;): The company name created is &quot;conuts doffee&quot;.
- (&quot;donuts&quot;, &quot;time&quot;): The company name created is &quot;tonuts dime&quot;.
- (&quot;donuts&quot;, &quot;toffee&quot;): The company name created is &quot;tonuts doffee&quot;.
- (&quot;time&quot;, &quot;donuts&quot;): The company name created is &quot;dime tonuts&quot;.
- (&quot;toffee&quot;, &quot;donuts&quot;): The company name created is &quot;doffee tonuts&quot;.
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- (&quot;coffee&quot;, &quot;time&quot;): The name &quot;toffee&quot; formed after swapping already exists in the original array.
- (&quot;time&quot;, &quot;toffee&quot;): Both names are still the same after swapping and exist in the original array.
- (&quot;coffee&quot;, &quot;toffee&quot;): Both names formed after swapping already exist in the original array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> ideas = [&quot;lack&quot;,&quot;back&quot;]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no valid selections. Therefore, 0 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= ideas.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= ideas[i].length &lt;= 10</code></li>
	<li><code>ideas[i]</code> consists of lowercase English letters.</li>
	<li>All the strings in <code>ideas</code> are <strong>unique</strong>.</li>
</ul>

# Solution:
# Intuition
Consider the example with all words from either `'a'` or `'b'`:
 {% highlight cpp %} 
ideas = ["apple","and","alpha","amaze","aye","aid","bye","bid","bat","beef","brown"]
 {% endhighlight %}
Based on the starting letter and the suffix we can see this pattern:
 {% highlight cpp %} 
'a': ["pple","nd","lpha","maze","ye","id"]
'b': ["ye","id","at","eef","rown"]
 {% endhighlight %}
Notice that `"ye"` and `"id"` are present in both. These cannot be used for company names because for example suppose we use `"aye","bat"` we will have `"bye aat"` as the company name but `"bye"` is present in original list of `ideas` hence not valid. So, we need to find the suffixes present in only one of the arrays:
 {% highlight cpp %} 
'a': ["pple","lpha","nd","maze"]
'b': ["at","eef","rown"]
 {% endhighlight %}
We can choose 12 pairs from here and from them we will have 24 company names:
 {% highlight cpp %} 
company_names = ["aat bpple", "bpple aat", "aeef bpple", "bpple aeef", "arown bpple", "bpple arown", "aat blpha", "blpha aat", "aeef blpha", "blpha aeef", "arown blpha", "blpha arown", "aat bnd", "bnd aat", "aeef bnd", "bnd aeef", "arown bnd", "bnd arown", "aat bmaze", "bmaze aat", "aeef bmaze", "bmaze aeef", "arown bmaze", "bmaze arown"]
 {% endhighlight %}
Hence answer for this example is 24.

# Approach
We will use 26 HashSets to store suffixes for each alphabet. For each pair of alphabets, we will add their contribution as $2*n1*n2$ where $n1,n2$ are the suffixes from each alphabet not present in the other one.

# Code
 {% highlight cpp %} 
class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long res = 0;
        vector<unordered_set<string>> ideaSet(26, unordered_set<string>{});
        for(string idea: ideas) ideaSet[idea[0]-'a'].insert(idea.substr(1));
        for (int i=0; i<26; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                int common=0;
                for(string idea: ideaSet[j]) common+=ideaSet[i].count(idea);
                int n1 = ideaSet[i].size()-common, n2=ideaSet[j].size()-common;
                res += 2LL*n1*n2;
            }
        }
        return res;
    }
};
 {% endhighlight %}

# Complexity
Worst case time complexity is $O(nm)$ where $n$ is the number of words in `ideas`, $m$ is the maximum size of word in `ideas` .
Space complexity: $O(nm)$

# Alternative solution
We can have slightly more efficient solution (same TC) if instead of storing suffixes we just maintain a 26x26 frequency table to check validity of name.
 {% highlight cpp %} 
class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long res = 0;
        unordered_set<string> ideaSet(ideas.begin(),ideas.end());
        vector<vector<int>>freq_table(26,vector<int>(26,0));
        for (string idea: ideas)
        {
            for(char ch='a'; ch<='z'; ch++)
            {
                string namePart = string(1,ch)+idea.substr(1);
                if(!ideaSet.count(namePart))
                    freq_table[idea[0]-'a'][ch-'a']++;
            }
        }
        for (int i=0; i<26; i++)
            for (int j=i+1; j<26; j++)
                res += 2LL*freq_table[i][j]*freq_table[j][i];
        return res;
    }
};
 {% endhighlight %}