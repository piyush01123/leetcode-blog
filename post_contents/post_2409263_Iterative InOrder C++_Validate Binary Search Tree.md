```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *prev; prev = NULL;
        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (prev && root->val <= prev->val) return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};
```
The above is the best solution for this as it requires O(1) space. 

A simpler O(N) space solution is to just do recursive  inorder traversal, store all elements in array and check that the array is sorted.  But this is not so impressive though it still does the job.
```
class Solution {
public:
    void inOrderTraversal(TreeNode *root, int *arr, int *n){
        if (root==NULL) return;
        inOrderTraversal(root->left, arr, n);
        *(arr+*n) = root->val;
        *n = *n+1;
        inOrderTraversal(root->right, arr, n);
    }
    bool isSorted(int arr[], int n){
        for (int i=1; i<n; i++){if (arr[i]<=arr[i-1]) return 0;} return 1; 
    }
    bool isValidBST(TreeNode* root) {
        int *arr = new int[10000000];
        int n=0;
        inOrderTraversal(root, arr, &n);
        return isSorted(arr, n);
    }
};
```