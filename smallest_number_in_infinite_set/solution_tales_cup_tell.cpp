class SmallestInfiniteSet {
public:
    set<int> myset;
    SmallestInfiniteSet() 
    {
        for(int i=1; i<=1000; i++) myset.insert(i);
    }
    
    int popSmallest() 
    {
        int res = *myset.begin();
        myset.erase(res);
        return res;
    }
    
    void addBack(int num) 
    {
        myset.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */