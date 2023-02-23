This is a plain DFS problem. Logic in comments.
```
class Solution {
public:
    void dfs(TreeNode *root, int val, int depth, int curDepth)
    {
        if (!root) return;
		// We need to insert as per the rule at this point
        if (depth==curDepth+1)
        {
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return;
        }
        dfs(root->left, val, depth, curDepth+1);
        dfs(root->right, val, depth, curDepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
		// Special case when we have to insert at root
        if (depth==1) return new TreeNode(val, root, NULL);
        dfs(root, val, depth, 1);
        return root;
    }
};
```