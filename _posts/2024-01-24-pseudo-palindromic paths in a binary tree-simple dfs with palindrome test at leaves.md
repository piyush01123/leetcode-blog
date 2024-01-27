---
layout: mypost
title: "Pseudo-Palindromic Paths in a Binary Tree - Simple DFS with palindrome test at leaves"
tags: ["Bit Manipulation", "Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "C++", "Medium"]
---
# Problem Statement:
<p>Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be <strong>pseudo-palindromic</strong> if at least one permutation of the node values in the path is a palindrome.</p>

<p><em>Return the number of <strong>pseudo-palindromic</strong> paths going from the root node to leaf nodes.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png" style="width: 300px; height: 201px;" /></p>

<pre>
<strong>Input:</strong> root = [2,3,1,3,1,null,1]
<strong>Output:</strong> 2 
<strong>Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png" style="width: 300px; height: 314px;" /></strong></p>

<pre>
<strong>Input:</strong> root = [2,1,1,1,3,null,null,null,null,null,1]
<strong>Output:</strong> 1 
<strong>Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [9]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 9</code></li>
</ul>

# Solution:
Given an array, how do we know if it can be rearranged into a palindrome? The answer is it can have at most one member with odd frequency. This will be the center. If there are no members with odd frequency then we can just put half of each member on each side.

So, given an array of frequencies of unique elements, we can apply the following test:
 {% highlight cpp %} 
bool isPalindrome(vector<int> frequencies)
{
    bool foundOdd=false;
    for(int f: frequencies) if(f%2)
    {
        if(foundOdd) return false; 
        else foundOdd=true;
    }
    return true;
}
 {% endhighlight %}

We can collect the frequencies and apply this test at each leaf node. To collect the frequencies of root node to leaf node, we use DFS.

 {% highlight cpp %} 
class Solution {
    int res = 0;
public:
    bool isPalindrome(vector<int> frequencies)
    {
        bool foundOdd=false;
        for(int f: frequencies) if(f%2)
        {
            if(foundOdd) return false; 
            else foundOdd=true;
        }
        return true;
    }
    void dfs(TreeNode* root, vector<int>&frequencies)
    {
        if(!root) return;
        frequencies[root->val]++;
        if(!root->left && !root->right) res+=isPalindrome(frequencies);
        dfs(root->left, frequencies);
        dfs(root->right, frequencies);
        frequencies[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int>frequencies(10,0);
        dfs(root,frequencies);        
        return res;
    }
};
 {% endhighlight %}