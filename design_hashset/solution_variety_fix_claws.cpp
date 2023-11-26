class MyHashSet {
    int N=1009;
    vector<vector<int>> A;
public:
    MyHashSet() {A.resize(N);}
    
    void add(int key) 
    {
        if(contains(key)) return;
        int h = key%N;
        A[h].push_back(key);
    }
    
    void remove(int key) 
    {
        if (!contains(key)) return;
        int h = key%N;
        vector<int>::iterator it = find(A[h].begin(),A[h].end(),key);
        A[h].erase(it);
    }
    
    bool contains(int key) 
    {
        int h = key%N;
        vector<int>::iterator it = find(A[h].begin(),A[h].end(),key);
        return it!=A[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */