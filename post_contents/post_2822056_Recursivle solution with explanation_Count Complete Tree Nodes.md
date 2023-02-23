First, let us define the concept of a "full" tree: a tree with no null nodes in the last level ie full upto its complete height.
(Consider height of root as 0, level 1 as 1 etc)
**IMP: What is the #(Nodes) in a full tree of height h**
Ans: `2^(h+1) - 1`

Now, given that we have "complete" tree of height `h`, we can say that either the left subtree is a "full" tree of height `h-1` or the right subtree is a "full" tree of height `h-2`. 

In the first case we have
```
countNodes(root) = 2^h + countNodes(root->right)
```
(`2^h = 2^h - 1` for left subtree and `1` for root)
and in the second case, we have

```
countNodes(root) = 2^(h-1) + countNodes(root->left)
```
(`2^(h-1) = 2^(h-1) - 1` for right subtree and `1` for root)

C++ code:
```
class Solution {
public:
    int height(TreeNode *root)
    {
        return root == NULL ? -1 : 1+height(root->left);
    }
    int countNodes(TreeNode* root) 
    {
        if (!root) return 0;
        int h = height(root);
        if (h==0) return 1;
        if (height(root->right)==h-1)
            return (1<<h) + countNodes(root->right);
        else
            return (1<<h-1) + countNodes(root->left);
        return -1;
    }
};
```
```
TC=O((log n)^2)
```
