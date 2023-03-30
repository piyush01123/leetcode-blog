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
public:
    bool getPath(TreeNode *node, int val, string &str)
    {
        if (node->val==val) return true;
        if (node->left && getPath(node->left, val, str)) str.push_back('L');
        else if (node->right && getPath(node->right, val, str)) str.push_back('R');
        return !str.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string s_path, d_path;
        getPath(root, startValue, s_path);
        getPath(root, destValue, d_path);
        cout << s_path << endl;
        cout << d_path << endl;
        while (!s_path.empty()&&!d_path.empty()&&s_path.back()==d_path.back())
        {
            s_path.pop_back();
            d_path.pop_back();
        }
        reverse(d_path.begin(),d_path.end());
        return string(s_path.size(), 'U')+d_path;
    }
};