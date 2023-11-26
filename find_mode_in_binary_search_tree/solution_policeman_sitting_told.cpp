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

class TreeIterator
{
public:
    stack<TreeNode*> nodes;
    TreeIterator(TreeNode *root){goLeft(root);}
    bool hasNext(){return !nodes.empty();}
    TreeNode *getNext()
    {
        TreeNode *cur = nodes.top();
        nodes.pop();
        if (cur->right) goLeft(cur->right);
        return cur;
    }
    void goLeft(TreeNode *root)
    {
        while(root){nodes.push(root); root=root->left;}
    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) 
    {
        TreeIterator itr = TreeIterator(root);
        vector<int> res;
        int cur_elem=itr.getNext()->val, cur_count=1;
        int max_elem=cur_elem, max_count=1;
        res.push_back(cur_elem);
        while (itr.hasNext())
        {
            int elem = itr.getNext()->val;
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
        }
        return res;
    }
};