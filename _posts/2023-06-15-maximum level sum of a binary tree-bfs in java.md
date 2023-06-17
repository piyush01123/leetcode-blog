---
layout: mypost
title: "Maximum Level Sum of a Binary Tree - BFS in Java"
tags: ["Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree", "Java", "Medium"]
---
# Problem Statement:
<p>Given the <code>root</code> of a binary tree, the level of its root is <code>1</code>, the level of its children is <code>2</code>, and so on.</p>

<p>Return the <strong>smallest</strong> level <code>x</code> such that the sum of all the values of nodes at level <code>x</code> is <strong>maximal</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/capture.JPG" style="width: 200px; height: 175px;" />
<pre>
<strong>Input:</strong> root = [1,7,0,7,-8,null,null]
<strong>Output:</strong> 2
<strong>Explanation: </strong>
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [989,null,10250,98693,-89388,null,null,null,-32127]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
This problem can be solved by BFS.

 {% highlight java %} 
public int maxLevelSum(TreeNode root) 
{
    int curLevel=1, resLevel=0, maxSum=Integer.MIN_VALUE;
    Queue<TreeNode> Q = new LinkedList<>();
    Q.add(root);
    while(!Q.isEmpty())
    {
        int curSum = 0;
        for(int i=Q.size(); i>0; i--)
        {
            TreeNode cur = Q.poll();
            curSum += cur.val;
            if(cur.left!=null) Q.add(cur.left);
            if(cur.right!=null) Q.add(cur.right);
        }
        if (curSum>maxSum)
        {
            maxSum = curSum;
            resLevel = curLevel;
        }
        curLevel++;
    }
    return resLevel;
}
 {% endhighlight %}
TC: $O(n)$, SC: $O(1)$