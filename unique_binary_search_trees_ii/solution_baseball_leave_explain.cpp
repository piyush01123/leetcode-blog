/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n, int s=1) 
    {
        if (s>n || s<=0) return {NULL};
        if (s==n) return {new TreeNode(n)};
        vector<TreeNode*> res;
        for(int i=s; i<=n; i++)
        {
            vector<TreeNode*> leftTrees = generateTrees(i-1,s);
            vector<TreeNode*> rightTrees = generateTrees(n, i+1);
            for(TreeNode *left: leftTrees) for(TreeNode *right: rightTrees)
                res.push_back(new TreeNode(i, left, right));
        }
        return res;
    }
};

/*
2,1
i=1->(0,1),(2,2)
i=2->(1,1),(2,3)
*/