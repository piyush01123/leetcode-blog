/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> A;
        if (root!=NULL)
        {
            for (Node* child: root->children)
            {
                cout << "Child Val " << child->val << endl;
                vector<int> B = postorder(child);
                for (int b: B){
                    A.push_back(b);
                }
            }
            cout << "Root Val " << root->val << endl;
            A.push_back(root->val);
        }
        return A;
    }
};