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
class BSTIterator {
public:
    vector<int>keys;
    int idx;
    void traverse(TreeNode *root, vector<int>&keys_v)
    {
        if (root==NULL) return;
        traverse(root->left, keys_v);
        keys_v.push_back(root->val);
        traverse(root->right, keys_v);
    }
    BSTIterator(TreeNode* root) {
        traverse(root, keys);
        idx=0;
        for (int k: keys) cout<<k<<';'; cout<<endl;
    }
    
    int next() {
        return keys[idx++];
    }
    
    bool hasNext() {
        return idx < keys.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */