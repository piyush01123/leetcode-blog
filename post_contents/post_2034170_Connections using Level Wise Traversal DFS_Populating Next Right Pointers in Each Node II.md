If you do not know [level order traversal problem](https://leetcode.com/problems/binary-tree-level-order-traversal/), refere here:
[Level Order Traversal - Two DFS solutions](https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/2034163/Two-DFS-solutions)
<br>
Now we can immediately think of a solution:
Instead of storing the keys, sotre the node pointers and then make required connections.
```
class Solution {
public:
    void dfs(Node *root, vector<vector<Node *>> &lvn, int level)
    {
        if (!root) return;
        if (level==lvn.size()) lvn.push_back({});
        lvn[level].push_back(root);
        dfs(root->left, lvn, level+1);
        dfs(root->right, lvn, level+1);
    }
    Node* connect(Node* root) {
        vector<vector<Node *>> levelWiseNodes;
        dfs(root, levelWiseNodes, 0);
        for (int i=0; i<levelWiseNodes.size(); i++)
        {
            if (levelWiseNodes[i].size()<2) continue;
            for (int j=0; j<=levelWiseNodes[i].size()-2; j++)
            {
               levelWiseNodes[i][j]->next = levelWiseNodes[i][j+1];
            }
        }
        return root;
    }
};
```
