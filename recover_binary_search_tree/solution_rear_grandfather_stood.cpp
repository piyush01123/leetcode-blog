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
    void inOrderTraversal(TreeNode *root, std::vector<int> &vals){
        if (root==nullptr) return;
        inOrderTraversal(root->left, vals);
        vals.push_back(root->val);
        inOrderTraversal(root->right, vals);
    }
    std::vector<int> outOfOrder(std::vector<int> nums){
        int x=-1, y=-1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i]<nums[i-1]){
                if (x==-1){ 
                    x=i-1; y=i;
                } else {
                    y = i; 
                }
            }
        }
        return std::vector<int> {nums[x], nums[y]};
    }
    void recoverTreeUtil(TreeNode *root, std::vector<TreeNode*> &nodes, int a, int b){
        if (root==nullptr) return;
        if (root->val==a || root->val==b) nodes.push_back(root);
        recoverTreeUtil(root->left, nodes, a, b);
        recoverTreeUtil(root->right, nodes, a, b);
    }
    void recoverTree(TreeNode* root) {
        std::vector<int> vals;
        inOrderTraversal(root, vals);
        std::vector<int> A = outOfOrder(vals);
        int a=A[0], b=A[1];
        std::vector<TreeNode*> nodes;
        recoverTreeUtil(root, nodes, a, b);
        TreeNode *n1 = nodes[0], *n2 = nodes[1];
        int cache = n1->val;
        n1->val = n2->val;
        n2->val = cache;
    }
};