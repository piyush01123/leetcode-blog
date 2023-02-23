# Easy Solution
Just traverse the array and store keys in an array. Then return answer from array.
```
class BSTIterator {
public:
    vector<int>keys;
    int idx;
    void traverse(TreeNode *root, vector<int>&keys_v)
    {
        if (root==NULL) return;
        traverse(root->left, keys_v);
        keys_v.push_back(root->val);
        traverse(root->right, keys_v);
    }
    BSTIterator(TreeNode* root) {
        traverse(root, keys);
        idx=0;
    }
    
    int next() {
        return keys[idx++];
    }
    
    bool hasNext() {
        return idx < keys.size();
    }
};
```
```
TC: O(1)
SC: O(n)
```
# Medium Solution
Use stack to go as left as possible accumulating the nodes. Then return from bottom left and move to right (Accumulate nodes from right node to left-wards).
```
class BSTIterator {
public:
    stack<TreeNode *>nodes;
    void pushLeft(TreeNode *root)
    {
        while (root!=NULL)
        {
            nodes.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        if (nodes.size()>0)
        {
            TreeNode *leftBottom = nodes.top();
            nodes.pop();
            pushLeft(leftBottom->right);
            return leftBottom->val;
        }
        else return -1;
        
    }
    
    bool hasNext() {
        return nodes.size()>0;
    }
};

```
```
TC: \u03B8(1) 
SC: O(h)
```