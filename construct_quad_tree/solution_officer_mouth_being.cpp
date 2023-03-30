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

int test(vector<vector<int>>&grid)
{
    int n = grid.size();
    int s = 0;
    for(auto &row:grid)for(int k:row)s+=k;
    if (s==0) return 0;
    if (s==(n*n)) return 1;
    return 2;
}

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        if (test(grid)==0) return new Node(0, 1);
        if (test(grid)==1) return new Node(1, 1);
        int n = grid.size();
        vector<vector<int>> tl, tr, bl, br;
        vector<vector<int>> top(grid.begin(),grid.begin()+n/2);
        vector<vector<int>> bot(grid.begin()+n/2,  grid.end());
        for (auto &vec: top)
        {
            tl.push_back(vector<int>(vec.begin(), vec.begin()+n/2));
            tr.push_back(vector<int>(vec.begin()+n/2,   vec.end()));
        }        
        for (auto &vec: bot)
        {
            bl.push_back(vector<int>(vec.begin(), vec.begin()+n/2));
            br.push_back(vector<int>(vec.begin()+n/2,   vec.end()));
        }
        return new Node(1, 0, construct(tl), construct(tr), \
            construct(bl), construct(br));
    }
};