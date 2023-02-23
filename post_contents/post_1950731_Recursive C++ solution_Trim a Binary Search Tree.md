The important observation is that:
**If  parent<low => parent->left < low**
Similarly
**If  parent>high => parent->right> high**
Thus we can reject the entire subtree depending on this condition.

We can build the tree recursively and return `root`.

```
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root==NULL) return root;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
```