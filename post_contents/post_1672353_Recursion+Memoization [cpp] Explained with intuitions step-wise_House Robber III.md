Let us start at the `root` node. Assume that `root->left` and `root->right` are both non-NULL and define the following:
```
TreeNode *L= root->left
TreeNode *R = root->right
TreeNode *LL = root->left->left
TreeNode *LR= root->left->right
TreeNode *RL = root->right->left
TreeNode *RR= root->right->right
```
Now, the recursive relation is:
```
rob(root)=max(rob(L)+rob(R),  root->val+rob(LL)+rob(LR)+rob(RL)+rob(RR))
```
If `root->left` is NULL, then we replace `rob(LL)+rob(LR)` with the value zero. Thus we have the following relation:
```
rob(root)=max(rob(R),  root->val+rob(RL)+rob(RR))
```
Similarly if `root->right` is NULL, we have the following relation
```
rob(root)=max(rob(L),  root->val+rob(LL)+rob(LR))
```


# Vanilla recursion Method

```
class Solution {
public:
    int rob(TreeNode* root) {
        if (root==NULL) return 0;
        TreeNode *l=root->left, *r=root->right, *ll, *lr, *rl, *rr;
        if (l){ll=l->left; lr=l->right;}
        if (r){rl=r->left; rr=r->right;}
        int a = (l)?rob(ll)+rob(lr):0;
        int b = (r)?rob(rl)+rob(rr):0;
        return max(root->val+a+b, rob(l)+rob(r));
    }
};
```
The logic is perfectly correct in above algorithm and passes for the two test cases given in description. However on submission it gives `TLE` for large tree.

# Memoization

Notice that in the vanilla method, we are calculating the value for each node multiple times. Hence we can do memoization to reduce complexity. The idea is to use an HashMap ie `unordered_map<TreeNode *, int>`. At each node we return from the HashMap if present else calculate the value and add to the HashMap and then return the same.



```
class Solution {
public:
    int helper(TreeNode *root, unordered_map<TreeNode *, int> &money)
    {
        if (root==NULL) return 0;
        if (money.find(root)!=money.end()) return money[root];
        TreeNode *l=root->left, *r=root->right, *ll, *lr, *rl, *rr;
        if (l){ll=l->left; lr=l->right;}
        if (r){rl=r->left; rr=r->right;}
        int a = (l)?helper(ll,money)+helper(lr,money):0;
        int b = (r)?helper(rl,money)+helper(rr,money):0;
        return money[root]=max(root->val+a+b, helper(l,money)+helper(r,money));
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> moneys;
        return helper(root, moneys);
    }
};
```

Time complexity: O(n)
Space complexity: O(n)

Please upvote and comment if you found this useful.
