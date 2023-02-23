```
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if (!head) return head;
        unordered_map<Node*,Node*> H;
        Node *curr = head;
        while(curr)
        {
            H[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr)
        {
            H[curr]->next = H[curr->next];
            H[curr]->random = H[curr->random];
            curr = curr->next;
        }
        return H[head];
    }
};
```