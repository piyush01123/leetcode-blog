class MyHashSet {
    vector<bool>A;
public:
    MyHashSet() {A=vector<bool>(1e6+3, false);}
    void add(int key) {A[key]=true;}
    void remove(int key) {A[key]=false;}
    bool contains(int key) {return A[key];}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */