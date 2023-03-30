void swap(string &a, string &b)
{
    string t = a;
    a = b;
    b = t;
}
class Bitset {
public:
    string curr, flipped;
    int bsz, num_ones;
    Bitset(int size) {
        bsz = size;
        curr = string(bsz, '0');
        flipped = string(bsz, '1');
        num_ones=0;
    }
    
    void fix(int idx) {
        if (curr[idx]=='0') num_ones++;
        curr[idx] = '1';
        flipped[idx] = '0';
    }
    
    void unfix(int idx) {
        if (curr[idx]=='1') num_ones--;
        curr[idx] = '0';
        flipped[idx] = '1';
    }
    
    void flip() {
        num_ones = bsz-num_ones;
        swap(curr, flipped);
    }
    
    bool all() {
        return num_ones==bsz;
    }
    
    bool one() {
        return num_ones>0;
    }
    
    int count() {
        return num_ones;
    }
    
    string toString() {
        return curr;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */