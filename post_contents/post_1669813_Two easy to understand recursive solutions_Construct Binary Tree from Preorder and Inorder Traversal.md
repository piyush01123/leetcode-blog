## Method-I:
- We know the root is at `preorder[0]`. Find the index of this element in `inorder` array. Call this `rootIndex`.
- In the `inorder` array, everything to the left of this element is in the left subtree and everything to the right is in the right subtree ie `inorder[:rootIndex]` is the inorder traversal of left subtree and `inorder[rootIndex+1:]` is the inorder traversal of the right subtree
- Now we can know the size of the left subtree and the right subtree from the above arrays. So we use this to form the preorder traversals of left and right subtree ie `preorder[1:rootIndex+1]` is the preorder traversal of left subtree and `preorder[rootIndex+1:]` is the preorder traversal of the right subtree
- Recursively form the tree using the above 4 arrays as left and right.

```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0||inorder.size()==0) return NULL;

        int rootIndex=0;
        while(inorder[rootIndex]!=preorder[0])  rootIndex++;
        vector<int> pre_left(preorder.begin()+1, preorder.begin()+rootIndex+1);
        vector<int> pre_right(preorder.begin()+rootIndex+1, preorder.end());
        vector<int> in_left(inorder.begin(), inorder.begin()+rootIndex);
        vector<int> in_right(inorder.begin()+rootIndex+1, inorder.end());

        TreeNode *root = new TreeNode;
        root->val = preorder[0];
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};
```

## Method -II
This is similar to the solution provided by Leetcode in java. I translated it in c++.

Basically we do the same method as method-I in a different manner. 

- Create a `HashMap<int, int>` and Keep indices of `inorder` array in the form `value: index`. 
- Initialize `preOrderIndex` as 0.
- Both these variables are class variables so that these can be changed during the function calls.
- Now we know that root is present at `preorder[0]`. So create the node with this value. Note that since we have a `preOrderIndex` variable, we can increment it and get this value from preorder array.
- Use the index map created earlier to find the index of this element in the `inorder` array.
- We know that to the left of this in `inorder` is the left subtree and to the right is the right subtree. So recursively call with appropriate left and right limits of inorder array.

```
class Solution {
    int preOrderIndex;
    unordered_map<int,int> inOrderIndexMap;
public:
    TreeNode *helper(vector<int>preorder, int left, int right)
    {
        if (left>right) return NULL;
        int rootVal = preorder[preOrderIndex];
        preOrderIndex++;
        int inOrderIndex = inOrderIndexMap[rootVal];
        TreeNode *root = new TreeNode;
        root->val = rootVal;
        root->left = helper(preorder, left, inOrderIndex-1);
        root->right = helper(preorder, inOrderIndex+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preOrderIndex=0;
        for(int i=0; i<inorder.size(); i++) inOrderIndexMap[inorder[i]]=i;
        return helper(preorder, 0, preorder.size()-1);
    }
};
```

I  personally  think method-I is easier and is what I would come up with when asked this problem during an interview.