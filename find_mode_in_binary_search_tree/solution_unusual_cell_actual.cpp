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
    vector<int> res;
    int cur_elem, cur_count, max_elem, max_count;
    bool first_element;

    void inorder(TreeNode *root)
    {
        if(!root) return;
        inorder(root->left);
        int elem = root->val;
        if (first_element)
        {
            first_element = false;
            cur_elem = elem;
            max_elem = elem;
            cur_count = 1;
            max_count = 1;
            res.push_back(elem);
            inorder(root->right);
            return;
        }
        if (elem==cur_elem) cur_count ++;
        else
        {
            cur_elem = elem;
            cur_count = 1;
        }
        if (cur_count>max_count)
        {
            max_elem = cur_elem;
            max_count = cur_count;
            res.clear();
            res.push_back(max_elem);
        }
        if (cur_count==max_count && cur_elem!=max_elem) res.push_back(cur_elem);
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) 
    {
        first_element = true;
        inorder(root);
        return res;
    }
};