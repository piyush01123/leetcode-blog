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
    void inOrder(TreeNode *root, vector<int>&vec)
    {
        if (!root) return;
        inOrder(root->left,vec);
        vec.push_back(root->val);
        inOrder(root->right,vec);
    }
    bool twoSum(vector<int>vec, int target)
    {
        int lo=0, hi=vec.size()-1;
        while(lo<hi)
        {
            if (vec[lo]+vec[hi]==target) return true;
            else if (vec[lo]+vec[hi]<target) lo++;
            else hi--;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> vec;
        inOrder(root, vec);
        return twoSum(vec, k);
    }
};