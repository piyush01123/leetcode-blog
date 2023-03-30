/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode *root, std::vector<TreeNode *> &nodes){
        if (root==nullptr) return;
        inOrderTraversal(root->left, nodes);
        nodes.push_back(root);
        inOrderTraversal(root->right, nodes);
    }
    void recoverTree(TreeNode* root) {
        std::vector<TreeNode *> nodes;
        inOrderTraversal(root, nodes);
        int n = nodes.size();
        TreeNode *n1, *n2;
        //1 7 3 4 5 6 2 8
        for (int i=1; i<n; i++){
            if (nodes[i]->val<nodes[i-1]->val){
                n1 = nodes[i-1];
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if (nodes[i]->val<nodes[i-1]->val){
                n2 = nodes[i];
                break;
            }            
        }
        int cache = n1->val;
        n1->val = n2->val;
        n2->val = cache;
    }
};

