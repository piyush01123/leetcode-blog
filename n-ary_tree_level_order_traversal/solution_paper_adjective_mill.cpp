/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node *root, vector<vector<int>> &res, int level)
    {
        if (!root) return;
        if (res.size()==level) res.push_back({});
        res[level].push_back(root->val);
        for (auto child: root->children) helper(child, res, level+1);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        return res;
    }
};