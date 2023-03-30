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
    void traverseTree(TreeNode *root, vector<int> &numbers)
    {
        if(!root) return;
        traverseTree(root->left, numbers);
        numbers.push_back(root->val);
        (traverseTree)(root->right, numbers);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1, nums2, nums;
        traverseTree(root1, nums1);
        traverseTree(root2, nums2);
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j]){nums.push_back(nums1[i]);i++;}
            else{nums.push_back(nums2[j]);j++;}
        }
        for(;i<nums1.size();i++)nums.push_back(nums1[i]);
        for(;j<nums2.size();j++)nums.push_back(nums2[j]);
        return nums;
    }
};