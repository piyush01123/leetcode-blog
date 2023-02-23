This is a standard BFS problem. BFS traversal always will use a queue and the way it works is you add all the adjoining nodes of current node to queue. Then for these newly added nodes traverse and add their children to the queue but remember to not traverse these children ie mark till where we had added the adjoining and traverse only till there. 

```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if  (!root) return {};
        queue<TreeNode *> Q;
        Q.push(root);
        int level = 1;
        vector<vector<int>> res;
        while(!Q.empty())
        {
            vector<int> levelVals;
            for (int i=Q.size()-1; i>=0; --i)
            {
                TreeNode *node = Q.front();
                levelVals.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                Q.pop();
            }
            if (level%2 == 0)
                reverse(levelVals.begin(), levelVals.end());
            res.push_back(levelVals);
            level ++;
        }
        return res;
    }
};
```

> Then for these newly added nodes traverse and add their children to the queue but remember to not traverse these children ie mark till where we had added the adjoining and traverse only till there.

For this reason in the inner for loop,
```
            for (int i=Q.size()-1; i>=0; --i)
```
works but the following wont work. Although the difference is very subtle.
```
            for (int i=0; i<Q.size(); ++i)
```
This is because `Q.size()` is going to change inside for loop so it can be used as initializer but not for termination criterion.