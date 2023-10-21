class Solution {
public:
    bool dfs(int root, vector<int>&lc, vector<int>&rc, unordered_set<int>&nodes)
    {
        if (root==-1) return true;
        if (nodes.count(root)) return false;
        nodes.insert(root);
        return dfs(lc[root], lc, rc, nodes) && dfs(rc[root], lc, rc, nodes);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        unordered_set<int> childrens;
        for (int i=0; i<n; i++){childrens.insert(leftChild[i]); childrens.insert(rightChild[i]);}
        childrens.erase(-1);
        if (childrens.size()!=n-1) return false;
        int root;
        unordered_set<int> nodes;
        return dfs(root, leftChild, rightChild, nodes);
    }
};