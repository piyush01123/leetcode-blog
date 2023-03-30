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
    vector<int> preorder(Node* root) 
    {
        if (!root) return {};
        stack<Node *> stk;
        stk.push(root);
        vector<int> res;
        while (!stk.empty())
        {
            Node *node = stk.top();
            stk.pop();
            res.push_back(node->val);
            auto children = node->children;
            for (int i=children.size()-1; i>=0; i--)
            {
                Node *child = children[i];
                if (child) stk.push(child);
            }
        }
        return res;
    }
};