/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    array<Node*, 2> leaves;
    vector<vector<int>> grid_;
    Node* construct(vector<vector<int>>& grid) 
    {
        grid_ = move(grid);
        leaves[0] = new Node(false,true);
        leaves[1] = new Node(true, true);
        return helper(0, 0, grid_.size());
    }
    Node *helper(int x, int y, int n)
    {
        if (n==1) return leaves[grid_[x][y]];
        n/=2;
        Node *tl = helper(x, y, n);
        Node *tr = helper(x, y+n, n);
        Node *bl = helper(x+n, y, n);
        Node *br = helper(x+n, y+n, n);
        if (tl==tr && tl==bl && tl==br) return tl;
        return new Node(grid_[x][y], false, tl, tr, bl, br);
    }
};