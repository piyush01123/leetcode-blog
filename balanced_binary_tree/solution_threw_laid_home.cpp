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
    int max (int a, int b){ return (b>a)?b:a;}
    int abs_diff(int a, int b){ return (b>=a)?(b-a):(a-b);}
    // int depth(TreeNode* root){
    //     if (root==nullptr) { return 0;}
    //     return max(depth(root->left), depth(root->right)) + 1;
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root==nullptr) return true;
    //     int d1 = depth(root->left);
    //     int d2 = depth(root->right);
    //     return abs_diff(d1,d2)<=1 && isBalanced(root->left) && isBalanced(root->right);
    // }


    bool isBalancedUtil(TreeNode *root, int *height){
        int lh = 0, rh = 0;
        if (root==nullptr) {*height=0; return true;}
        bool lbal = isBalancedUtil(root->left, &lh);
        bool rbal = isBalancedUtil(root->right, &rh);
        *height = max(lh,rh) + 1;
        if (abs_diff(lh,rh)>1){return false;}
        return lbal && rbal;
    }
        
    bool isBalanced(TreeNode* root) {
     int height=0;
     return isBalancedUtil(root, &height);
    }

};


//     // G4G
//     bool isBalancedUtil(TreeNode* root, int* height) 
//     { 

//         /* lh --> Height of left subtree  
//         rh --> Height of right subtree */
//         int lh = 0, rh = 0; 

//         /* l will be true if left subtree is balanced  
//         and r will be true if right subtree is balanced */
//         int l = 0, r = 0; 

//         if (root == NULL) { 
//             *height = 0; 
//             return 1; 
//         } 

//         /* Get the heights of left and right subtrees in lh and rh  
//         And store the returned values in l and r */
//         l = isBalancedUtil(root->left, &lh); 
//         r = isBalancedUtil(root->right, &rh); 

//         /* Height of current node is max of heights of left and  
//         right subtrees plus 1*/
//         *height = (lh > rh ? lh : rh) + 1; 

//         /* If difference between heights of left and right  
//         subtrees is more than 2 then this node is not balanced  
//         so return 0 */
//         if (abs_diff(lh, rh) >= 2) 
//             return 0; 

//         /* If this node is balanced and left and right subtrees  
//         are balanced then return true */
//         else
//             return l && r; 
//     }

