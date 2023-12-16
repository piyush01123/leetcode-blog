class Solution {
public:
    int count(int root, vector<int>&lc, vector<int>&rc)
    {
        if (root<0) return 0;
        return 1 + count(lc[root],lc,rc) + count(rc[root],lc,rc);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int> inDegree(n,0);
        for (int i=0;i<n;i++)
        {
            int lc = leftChild[i], rc=rightChild[i];
            if (lc>=0) if (inDegree[lc]) return false; else inDegree[lc]++;
            if (rc>=0) if (inDegree[rc]) return false; else inDegree[rc]++;
        }
        int root = -1;
        for (int i=0; i<n; i++) if (!inDegree[i]) if (root>=0) return false; else root = i;
        if (root<0) return false;
        return count(root,leftChild,rightChild)==n;
    }
};