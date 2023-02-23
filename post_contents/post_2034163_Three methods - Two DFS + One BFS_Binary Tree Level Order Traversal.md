Method 1 is to get height of tree, then for each number less than tree height, traverse the tree and get all keys at that level using DFS.
```
class Solution {
public:
    int height(TreeNode *root)
    {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void dfs(TreeNode *root, vector<int>&levelVals, int h)
    {
        if (!root || h<0) return;
        if (h==0) levelVals.push_back(root->val);
        dfs(root->left, levelVals, h-1);
        dfs(root->right, levelVals, h-1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int H = height(root);
        vector<vector<int>> res;
        for (int h=0; h<H; h++)
        {
            vector<int> levelVals;
            dfs(root, levelVals, h);
            res.push_back(levelVals);
        }
        return res;
    }
};
```
Method 2 is to do DFS without getting height. Use the logic that if while going down from top, we are at same level as the size of keys array we append a new array and store keys of lower level in new array. 
```
class Solution {
public:
    void dfs(TreeNode *root, vector<vector<int>>&res, int level)
    {
        if (!root) return;
        if (res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        dfs(root->left, res, level+1);
        dfs(root->right, res, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        return res;
    }
};
```

BFS Solution:
Here we will need a queue. The children of the level nodes are stored in queue. Then one by one we go over the queue.
```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root) return {};
        vector<vector<int>>res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            vector<int> levelVals;
			// We cant go from 0 to Q.size() because Q.size() changes inside for loop
			// Hence we initialize i once using Q.size() and iterate in reverse.
            for (int i=Q.size()-1; i>=0; i--)
            {
                TreeNode *node = Q.front();
                Q.pop();
                levelVals.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
            res.push_back(levelVals);
        }
        return res;
    }
};
```