/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root) return NULL;
        queue<Node *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            Node *curr=NULL, *prev=NULL;
            for (int i=Q.size()-1; i>=0; --i)
            {
                curr = Q.front();
                if (prev) prev->next = curr;
                Q.pop();
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
                prev = curr;
            }
            curr->next = NULL;
        }
        return root;
    }
};