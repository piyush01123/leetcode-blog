/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head){
        int l=0;
        while (head!=NULL){l++; head=head->next;}
        return l;
    }
    TreeNode *sortedListToBSTUtil(ListNode * &head, int n){
        if (n<=0) return NULL;
        TreeNode *left = sortedListToBSTUtil(head, n/2);
        TreeNode *root = new TreeNode(head->val);
        // root->val = head->val;
        head = head->next;
        TreeNode *right = sortedListToBSTUtil(head, n-n/2-1);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int l = this->getLength(head);
        TreeNode *root = sortedListToBSTUtil(head, l);
        return root;
    }
};