---
layout: mypost
title: "Construct Quad Tree - 3 ways to do recursion, flyweight pattern"
tags: ["Array", "Divide and Conquer", "Tree", "Matrix", "C++", "Recursion", "Medium"]
---
# Problem Statement:
<p>Given a <code>n * n</code> matrix <code>grid</code> of <code>0&#39;s</code> and <code>1&#39;s</code> only. We want to represent the <code>grid</code> with a Quad-Tree.</p>

<p>Return <em>the root of the Quad-Tree</em> representing the <code>grid</code>.</p>

<p>Notice that you can assign the value of a node to <strong>True</strong> or <strong>False</strong> when <code>isLeaf</code> is <strong>False</strong>, and both are <strong>accepted</strong> in the answer.</p>

<p>A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:</p>

<ul>
	<li><code>val</code>: True if the node represents a grid of 1&#39;s or False if the node represents a grid of 0&#39;s.</li>
	<li><code>isLeaf</code>: True if the node is leaf node on the tree or False if the node has the four children.</li>
</ul>

<pre>
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}</pre>

<p>We can construct a Quad-Tree from a two-dimensional area using the following steps:</p>

<ol>
	<li>If the current grid has the same value (i.e all <code>1&#39;s</code> or all <code>0&#39;s</code>) set <code>isLeaf</code> True and set <code>val</code> to the value of the grid and set the four children to Null and stop.</li>
	<li>If the current grid has different values, set <code>isLeaf</code> to False and set <code>val</code> to any value and divide the current grid into four sub-grids as shown in the photo.</li>
	<li>Recurse for each of the children with the proper sub-grid.</li>
</ol>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/new_top.png" style="width: 777px; height: 181px;" />
<p>If you want to know more about the Quad-Tree, you can refer to the <a href="https://en.wikipedia.org/wiki/Quadtree">wiki</a>.</p>

<p><strong>Quad-Tree format:</strong></p>

<p>The output represents the serialized format of a Quad-Tree using level order traversal, where <code>null</code> signifies a path terminator where no node exists below.</p>

<p>It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list <code>[isLeaf, val]</code>.</p>

<p>If the value of <code>isLeaf</code> or <code>val</code> is True we represent it as <strong>1</strong> in the list <code>[isLeaf, val]</code> and if the value of <code>isLeaf</code> or <code>val</code> is False we represent it as <strong>0</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/11/grid1.png" style="width: 777px; height: 99px;" />
<pre>
<strong>Input:</strong> grid = [[0,1],[1,0]]
<strong>Output:</strong> [[0,1],[1,0],[1,1],[1,1],[1,0]]
<strong>Explanation:</strong> The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/e1tree.png" style="width: 777px; height: 186px;" />
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/e2mat.png" style="width: 777px; height: 343px;" /></p>

<pre>
<strong>Input:</strong> grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
<strong>Output:</strong> [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
<strong>Explanation:</strong> All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/12/e2tree.png" style="width: 777px; height: 328px;" />
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>n == 2<sup>x</sup></code> where <code>0 &lt;= x &lt;= 6</code></li>
</ul>

# Solution:
## Recursion - I
We use a `test` function to see if a grid is a leaf node or not and if not, we recurse into 4 sub-grids.

 {% highlight cpp %} 
int test(vector<vector<int>>&grid)
{
    int n = grid.size();
    int s = 0;
    for(auto &row:grid)for(int k:row)s+=k;
    if (s==0) return 0;
    if (s==(n*n)) return 1;
    return 2;
}

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        if (test(grid)==0) return new Node(0, 1);
        if (test(grid)==1) return new Node(1, 1);
        int n = grid.size();
        vector<vector<int>> tl, tr, bl, br;
        vector<vector<int>> top(grid.begin(),grid.begin()+n/2);
        vector<vector<int>> bot(grid.begin()+n/2,  grid.end());
        for (auto &vec: top)
        {
            tl.push_back(vector<int>(vec.begin(), vec.begin()+n/2));
            tr.push_back(vector<int>(vec.begin()+n/2,   vec.end()));
        }        
        for (auto &vec: bot)
        {
            bl.push_back(vector<int>(vec.begin(), vec.begin()+n/2));
            br.push_back(vector<int>(vec.begin()+n/2,   vec.end()));
        }
        return new Node(1, 0, construct(tl), construct(tr), \
            construct(bl), construct(br));
    }
};
 {% endhighlight %}

## Recusion - II
We don't actually need a `test` function because a helper function can do that that job while recursing.
 {% highlight cpp %} 
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        return helper(0, 0, grid.size(), grid);
    }
    Node *helper(int x, int y, int n, vector<vector<int>>&grid)
    {
        if (n==1) return new Node(grid[x][y], true);
        Node *tl = helper(x, y, n/2, grid);
        Node *tr = helper(x, y+n/2, n/2, grid);
        Node *bl = helper(x+n/2, y, n/2, grid);
        Node *br = helper(x+n/2, y+n/2, n/2, grid);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && \
            tl->val==tr->val && tl->val==bl->val && tl->val==br->val
           ) return new Node(tl->val, true);
        return new Node(grid[x][y], false, tl, tr, bl, br);
    }
};
 {% endhighlight %}

## Recusion - III (FLyweight pattern)
We can take advantage of the fact that there are fixed number of unique values in the grid: 2.
So, we can pre-construct a `leaves` array and reference leaf nodes from here. Notice also that `Node` object does not keep track of the size of grid. We can use this fact to create leaf nodes representing larger grids with the same pre-computed `leaves` array.
 {% highlight cpp %} 
class Solution {
public:
    vector<Node *> leaves = vector<Node *>(2);
    Node* construct(vector<vector<int>>& grid) 
    {
        leaves[0] = new Node(false,true);
        leaves[1] = new Node(true, true);
        return helper(0, 0, grid.size(), grid);
    }
    Node *helper(int x, int y, int n, vector<vector<int>>&grid)
    {
        if (n==1) return leaves[grid[x][y]];
        Node *tl = helper(x, y, n/2, grid);
        Node *tr = helper(x, y+n/2, n/2, grid);
        Node *bl = helper(x+n/2, y, n/2, grid);
        Node *br = helper(x+n/2, y+n/2, n/2, grid);
        if (tl==tr && tl==bl && tl==br) return tl;
        return new Node(grid[x][y], false, tl, tr, bl, br);
    }
};

 {% endhighlight %}
The 3rd solution is inspired from [here](https://leetcode.com/problems/construct-quad-tree/solutions/314379/c-flyweight-pattern-overwhelmingly-beats-100-time-and-memory/?q=fly&orderBy=most_relevant) and is called "Flyweight Pattern" because entire tree is constructed using 2 `Node` objects stored in `leaves`.