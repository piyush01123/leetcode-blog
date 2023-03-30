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
    vector<int>getSwappedIndices(vector<TreeNode *> nodes)
    {
        int n=nodes.size();
        int l=0, r=n-1, idx1=-1, idx2=-1;
        while (idx1==-1 || idx2==-1)
        {
            if (nodes[l]->val > nodes[l+1]->val) idx1=l;
            else l++;
            if (nodes[r]->val < nodes[r-1]->val) idx2=r;
            else r--;
        }
        return {idx1, idx2};
    }
    void swap(TreeNode *n1, TreeNode *n2)
    {
        int t=n1->val;
        n1->val=n2->val;
        n2->val=t;
    }
    void recoverTree(TreeNode* root) {
        std::vector<TreeNode *> nodes;
        inOrderTraversal(root, nodes);
        vector<int> swapped = getSwappedIndices(nodes);
        int idx1=swapped[0], idx2=swapped[1];
        swap(nodes[idx1], nodes[idx2]);
    }
};
