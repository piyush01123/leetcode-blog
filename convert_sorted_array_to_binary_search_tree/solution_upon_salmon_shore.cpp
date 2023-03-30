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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return NULL;
        vector<int> lefts(nums.begin(), nums.begin()+n/2);
        vector<int> rights(nums.begin()+n/2+1, nums.end());
        TreeNode *left = sortedArrayToBST(lefts);
        TreeNode *right = sortedArrayToBST(rights);
        return new TreeNode(nums[n/2],left,right);
    }
};