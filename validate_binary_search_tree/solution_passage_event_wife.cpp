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
        for (int i=0; i<n; i++){cout << *(arr+i) << ' ';} cout << '\n';
        cout<<"N="<<n<<'\n';
        return isSorted(arr, n);
    }
};


//       if (root==NULL) return true;
//       bool left_bal = isValidBST(root->left);
//       bool right_bal = isValidBST(root->right);
//       bool left_test = (root->left==NULL)?1:root->left->val<root->val;
//       bool right_test = (root->right==NULL)?1:root->val<root->right->val;
//       return left_bal && right_bal && left_test && right_test;        

