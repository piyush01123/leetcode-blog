class Node {
    public:
    int key;
    int val;
    Node *next;
    Node(int k, int v, Node *n){key=k;val=v;next=n;}
};

class MyHashMap {
public:
    vector<Node *>nodes;
    int N;
    MyHashMap(int n=99991) {
        nodes = vector<Node *>(n,NULL);
        N = n;        
    }
    
    void put(int key, int value) {
        int h = key%N;
        if (nodes[h]==NULL)
        {
            nodes[h]=new Node(key,value,NULL);
            return;
        }
        Node *curr=nodes[h];
        while (curr!=NULL)
        {
            if (curr->key==key)
            {
                curr->val=value;
                return;
            }
            curr=curr->next;
        }
        while (curr->next!=NULL) curr=curr->next;
        curr->next=new Node(key,value,NULL);
    }
    
    int get(int key) {
        int h = key%N;
        if (nodes[h]==NULL) return -1;
        Node *curr = nodes[h];
        while (curr!=NULL)
        {
            if (curr->key==key) return curr->val;
            curr=curr->next;
        }
        return -2;
    }
    
    void remove(int key) {
        int h=key%N;
        if (nodes[h]==NULL) return;
        if (nodes[h]->key==key) 
        {
            nodes[h]=nodes[h]->next;
            return;
        }
        Node *curr=nodes[h];
        while (curr->next!=NULL && curr->next->key!=key) curr=curr->next;
        curr->next = curr->next->next;        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */