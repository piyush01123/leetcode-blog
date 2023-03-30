---
layout: mypost
title: "Longest Absolute File Path - Monotonic stack solution explained"
tags: ["String", "Stack", "Depth-First Search", "C++", "Monotonic Stack", "Medium"]
---
# Problem Statement:
<p>Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/mdir.jpg" style="width: 681px; height: 322px;" /></p>

<p>Here, we have <code>dir</code> as the only directory in the root. <code>dir</code> contains two subdirectories, <code>subdir1</code> and <code>subdir2</code>. <code>subdir1</code> contains a file <code>file1.ext</code> and subdirectory <code>subsubdir1</code>. <code>subdir2</code> contains a subdirectory <code>subsubdir2</code>, which contains a file <code>file2.ext</code>.</p>

<p>In text form, it looks like this (with ⟶ representing the tab character):</p>

<pre>
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
</pre>

<p>If we were to write this representation in code, it will look like this: <code>&quot;dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext&quot;</code>. Note that the <code>&#39;\n&#39;</code> and <code>&#39;\t&#39;</code> are the new-line and tab characters.</p>

<p>Every file and directory has a unique <strong>absolute path</strong> in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by <code>&#39;/&#39;s</code>. Using the above example, the <strong>absolute path</strong> to <code>file2.ext</code> is <code>&quot;dir/subdir2/subsubdir2/file2.ext&quot;</code>. Each directory name consists of letters, digits, and/or spaces. Each file name is of the form <code>name.extension</code>, where <code>name</code> and <code>extension</code> consist of letters, digits, and/or spaces.</p>

<p>Given a string <code>input</code> representing the file system in the explained format, return <em>the length of the <strong>longest absolute path</strong> to a <strong>file</strong> in the abstracted file system</em>. If there is no file in the system, return <code>0</code>.</p>

<p><strong>Note</strong> that the testcases are generated such that the file system is valid and no file or directory name has length 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/dir1.jpg" style="width: 401px; height: 202px;" />
<pre>
<strong>Input:</strong> input = &quot;dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext&quot;
<strong>Output:</strong> 20
<strong>Explanation:</strong> We have only one file, and the absolute path is &quot;dir/subdir2/file.ext&quot; of length 20.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/dir2.jpg" style="width: 641px; height: 322px;" />
<pre>
<strong>Input:</strong> input = &quot;dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext&quot;
<strong>Output:</strong> 32
<strong>Explanation:</strong> We have two files:
&quot;dir/subdir1/file1.ext&quot; of length 21
&quot;dir/subdir2/subsubdir2/file2.ext&quot; of length 32.
We return 32 since it is the longest absolute path to a file.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> input = &quot;a&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> We do not have any files, just a single directory named &quot;a&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= input.length &lt;= 10<sup>4</sup></code></li>
	<li><code>input</code> may contain lowercase or uppercase English letters, a new line character <code>&#39;\n&#39;</code>, a tab character <code>&#39;\t&#39;</code>, a dot <code>&#39;.&#39;</code>, a space <code>&#39; &#39;</code>, and digits.</li>
	<li>All file and directory names have <strong>positive</strong> length.</li>
</ul>

# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Monotonic stack will be very useful here because we need to keep track of length of directory at current depth.

# Approach
<!-- Describe your approach to solving the problem. -->
We will maintain the stack of `(depth, length of path)` and for each entry, we will keep popping from stack till we are at the correct depth.
Example 1:
 {% highlight cpp %} 
dir: [(0,3)]
	subdir1: [(0,3)(1,11)]
	subdir2: [(0,3)(1,11)]
		file.ext: [(0,3)(1,11)(2,20)]
 {% endhighlight %}
Example 2:
 {% highlight cpp %} 
dir: [(0,3)]
	subdir1: [(0,3)(1,11)]
		file1.ext: [(0,3)(1,11)(2,21)]
		subsubdir1: [(0,3)(1,11)(2,22)]
	subdir2: [(0,3)(1,11)]
		subsubdir2: [(0,3)(1,11)(2,22)]
			file2.ext: [(0,3)(1,11)(2,22)(3,32)]
 {% endhighlight %}
# Complexity
- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
 {% highlight cpp %} 
class Solution {
public:
    int lengthLongestPath(string input) 
    {
        stringstream ss(input);
        string line;
        vector<string> lines;
        while (getline(ss, line, '\
')) lines.push_back(line);
        stack<pair<int,int>> stk;
        int res=0;
        for (auto &line: lines)
        {
            int tabs=0;
            while (line[tabs]=='	') tabs++;
            while (!stk.empty() && tabs<=stk.top().first) stk.pop();
            int cur = (stk.empty() ? line.length() : stk.top().second+1+line.length()-tabs);
            stk.push({tabs, cur});
            if (find(line.begin(),line.end(),'.')!=line.end()) res = max(res,cur);
        }
        return res;
    }
};
 {% endhighlight %}