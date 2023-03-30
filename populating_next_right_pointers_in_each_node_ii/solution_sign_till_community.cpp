/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

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