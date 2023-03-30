---
layout: mypost
title: "House Robber III - Recursion+Memoization [cpp] Explained with intuitions step-wise"
tags: ["Dynamic Programming", "Tree", "Depth-First Search", "Binary Tree", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>The thief has found himself a new place for his thievery again. There is only one entrance to this area, called <code>root</code>.</p>

<p>Besides the <code>root</code>, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if <strong>two directly-linked houses were broken into on the same night</strong>.</p>

<p>Given the <code>root</code> of the binary tree, return <em>the maximum amount of money the thief can rob <strong>without alerting the police</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg" style="width: 277px; height: 293px;" />
<pre>
<strong>Input:</strong> root = [3,2,3,null,3,null,1]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg" style="width: 357px; height: 293px;" />
<pre>
<strong>Input:</strong> root = [3,4,5,1,3,null,1]
<strong>Output:</strong> 9
<strong>Explanation:</strong> Maximum amount of money the thief can rob = 4 + 5 = 9.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution:
Let us start at the `root` node. Assume that `root->left` and `root->right` are both non-NULL and define the following:
 {% highlight cpp %} 
TreeNode *L= root->left
TreeNode *R = root->right
TreeNode *LL = root->left->left
TreeNode *LR= root->left->right
TreeNode *RL = root->right->left
TreeNode *RR= root->right->right
 {% endhighlight %}
Now, the recursive relation is:
 {% highlight cpp %} 
rob(root)=max(rob(L)+rob(R),  root->val+rob(LL)+rob(LR)+rob(RL)+rob(RR))
 {% endhighlight %}
If `root->left` is NULL, then we replace `rob(LL)+rob(LR)` with the value zero. Thus we have the following relation:
 {% highlight cpp %} 
rob(root)=max(rob(R),  root->val+rob(RL)+rob(RR))
 {% endhighlight %}
Similarly if `root->right` is NULL, we have the following relation
 {% highlight cpp %} 
rob(root)=max(rob(L),  root->val+rob(LL)+rob(LR))
 {% endhighlight %}


# Vanilla recursion Method

 {% highlight cpp %} 
class Solution {
public:
    int rob(TreeNode* root) {
        if (root==NULL) return 0;
        TreeNode *l=root->left, *r=root->right, *ll, *lr, *rl, *rr;
        if (l){ll=l->left; lr=l->right;}
        if (r){rl=r->left; rr=r->right;}
        int a = (l)?rob(ll)+rob(lr):0;
        int b = (r)?rob(rl)+rob(rr):0;
        return max(root->val+a+b, rob(l)+rob(r));
    }
};
 {% endhighlight %}
The logic is perfectly correct in above algorithm and passes for the two test cases given in description. However on submission it gives `TLE` for large tree.

# Memoization

Notice that in the vanilla method, we are calculating the value for each node multiple times. Hence we can do memoization to reduce complexity. The idea is to use an HashMap ie `unordered_map<TreeNode *, int>`. At each node we return from the HashMap if present else calculate the value and add to the HashMap and then return the same.



 {% highlight cpp %} 
class Solution {
public:
    int helper(TreeNode *root, unordered_map<TreeNode *, int> &money)
    {
        if (root==NULL) return 0;
        if (money.find(root)!=money.end()) return money[root];
        TreeNode *l=root->left, *r=root->right, *ll, *lr, *rl, *rr;
        if (l){ll=l->left; lr=l->right;}
        if (r){rl=r->left; rr=r->right;}
        int a = (l)?helper(ll,money)+helper(lr,money):0;
        int b = (r)?helper(rl,money)+helper(rr,money):0;
        return money[root]=max(root->val+a+b, helper(l,money)+helper(r,money));
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> moneys;
        return helper(root, moneys);
    }
};
 {% endhighlight %}

Time complexity: O(n)
Space complexity: O(n)

Please upvote and comment if you found this useful.
