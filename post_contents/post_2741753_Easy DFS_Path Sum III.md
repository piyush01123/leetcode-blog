The idea is that any valid path will have a starting node and go down thereafter. So, we start from root and go down while checking if there is valid path starting from that node.
So, for the tree in the question example 1:
```
root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
```
We will check paths 
```
[10],[10,5],[10,5,3],[10,5,3,3],[10,5,3,-2],[10,5,2],[10,5,2,1],[10,-3],[10,-3,11]
```
Then we will check paths
```
[5],[5,3],[5,3,3],[5,3,-2],[5,2],[5,2,1]
```
and so on.

C++ code:
```
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        if (!root) return 0;
        return sumUp(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    int sumUp(TreeNode *root, long long curr, int target)
    {
        if (!root) return 0;
        curr += root->val;
        return (curr==target) + sumUp(root->left, curr, target) + sumUp(root->right,curr,target);
    }
};
```