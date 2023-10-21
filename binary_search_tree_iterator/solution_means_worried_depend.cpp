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
    stack<TreeNode *> myStack;
    void util(TreeNode *root)
    {
        while(root)
        {
            myStack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) 
    {
        util(root);
    }
    
    int next() 
    {
        TreeNode *cur = myStack.top();
        myStack.pop();
        if (cur->right) util(cur->right);
        return cur->val;
    }
    
    bool hasNext() {return !myStack.empty();}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */