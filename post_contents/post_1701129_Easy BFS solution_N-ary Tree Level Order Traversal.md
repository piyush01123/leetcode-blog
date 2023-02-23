We had this solution for Level order traversal in Binary Tree:
```
void helper(TreeNode *root, vector<vector<int>> &res, int level)
{
	if (!root) return;
	if (res.size()==level) res.push_back({});
	res[level].push_back(root->val);
	helper(root->left, res, level+1);
	helper(root->right, res, level+1);
}
vector<vector<int>> levelOrder(TreeNode* root) 
{
	vector<vector<int>> res;
	helper(root, res, 0);
	return res;
}
```

We can modify this for N-ary tree as:
```
void helper(Node *root, vector<vector<int>> &res, int level)
{
	if (!root) return;
	if (res.size()==level) res.push_back({});
	res[level].push_back(root->val);
	for (auto child: root->children) helper(child, res, level+1);
}
vector<vector<int>> levelOrder(Node* root) 
{
	vector<vector<int>> res;
	helper(root, res, 0);
	return res;
}
```