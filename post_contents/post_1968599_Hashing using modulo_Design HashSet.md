Here we use modulo operator as the hashing function and M is chosen to be a big enough prime.
```
class Node {
    public:
    int val;
    Node *next;
    Node(int v, Node *n){val=v;next=n;}
};
class MyHashSet {
public:
    vector<Node *>nodes;
    int N;
    MyHashSet(int n=99991) {
        nodes = vector<Node *>(n,NULL);
        N = n;
    }
    
    void add(int key) {
        if (contains(key)) return;
        int h = key%N;
        if (nodes[h]==NULL) nodes[h]=new Node(key,NULL);
        else
        {
            Node *curr=nodes[h];
            while (curr->next!=NULL) curr=curr->next;
            curr->next=new Node(key,NULL);
        }
    }
    
    void remove(int key) {
        if (!contains(key)) return;
        int h=key%N;
        if (nodes[h]->val==key) 
        {
            nodes[h]=nodes[h]->next;
            return;
        }
        Node *curr=nodes[h];
        while (curr->next!=NULL && curr->next->val!=key) curr=curr->next;
        curr->next = curr->next->next;
    }
    
    bool contains(int key) {
        int h=key%N;
        if (nodes[h]==NULL) return false;
        Node *curr=nodes[h];
        while (curr!=NULL) 
        {
            if (curr->val==key) return true;
            curr=curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```