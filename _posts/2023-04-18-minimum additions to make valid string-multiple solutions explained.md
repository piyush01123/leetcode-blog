---
layout: mypost
title: "Minimum Additions to Make Valid String - Multiple solutions explained"
tags: ["String", "Dynamic Programming", "Stack", "Greedy", "C++", "Medium"]
---
# Problem Statement:
<p>Given a string <code>word</code> to which you can insert letters &quot;a&quot;, &quot;b&quot; or &quot;c&quot; anywhere and any number of times, return <em>the minimum number of letters that must be inserted so that <code>word</code> becomes <strong>valid</strong>.</em></p>

<p>A string is called <strong>valid </strong>if it can be formed by concatenating the string &quot;abc&quot; several times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;b&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> Insert the letter &quot;a&quot; right before &quot;b&quot;, and the letter &quot;c&quot; right next to &quot;a&quot; to obtain the valid string &quot;<strong>a</strong>b<strong>c</strong>&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;aaa&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> Insert letters &quot;b&quot; and &quot;c&quot; next to each &quot;a&quot; to obtain the valid string &quot;a<strong>bc</strong>a<strong>bc</strong>a<strong>bc</strong>&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;abc&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> word is already valid. No modifications are needed. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>word</code> consists of letters &quot;a&quot;, &quot;b&quot;&nbsp;and &quot;c&quot; only.&nbsp;</li>
</ul>

# Solution:
**First approach:** This is a very simple case-by-case approach. Since the number of unique characters in `word` is 3, we can enumerate all cases and handle them separately. If we encounter an `"abc"` then we can simply move ahead 3 positions. If we see one of `"ab", "bc", "ac"`, we can move ahead two steps and increment answer by one. In all other casaes, we need to increment answer by one and move ahead single step.
 {% highlight cpp %} 
int addMinimum(string word) 
{
    int n = word.length(), i=0, res=0;
    while (i<n)
    {
        if (i+2<n && word[i]=='a' & word[i+1]=='b' & word[i+2]=='c')
            i+= 3;
        else if (i+1<n && word[i]=='a' && word[i+1]=='b') 
            {res+=1; i+=2;}
        else if (i+1<n && word[i]=='b' && word[i+1]=='c') 
            {res+=1; i+=2;}
        else if (i+1<n && word[i]=='a' && word[i+1]=='c') 
            {res+=1; i+=2;}
        else {res+=2; i+=1;}
    }
    return res;
}
 {% endhighlight %}
**Second approach:** We can improve above logic and make our code more elegant but it does essentially the same thing.
 {% highlight cpp %} 
int addMinimum(string word) 
{
    int n=word.length(), i=0, res=0;
    while (i<n)
    {
        int ctr = 0;
        if (word[i]=='a'){ctr++; i++;}
        if (word[i]=='b'){ctr++; i++;}
        if (word[i]=='c'){ctr++; i++;}
        res += (3-ctr);
    }
    return res;
}
 {% endhighlight %}
**Third approach:** We can make the code even more elegant by treating `word` as a subsequence of another string which is just `"abc"` repeated a number of times, say `lenby3` so that the length of the subsequence is `3*lenby3`. Our answer is the difference in the lengths of this subsequence and of `word`. To find `lenby3`, the logic is that after the first character, it has to increment every time current character is no more than the previous.
 {% highlight cpp %} 
int addMinimum(string word) 
{
    char prev='d';
    int n=word.length(), lenby3=0;
    for (int i=0;  i<n; i++)
    {
        lenby3 += (word[i]<=prev);
        prev = word[i];
    }
    return 3*lenby3-word.length();
}
 {% endhighlight %}
All 3 approaches have $O(n)$ TC and $O(1)$ SC.