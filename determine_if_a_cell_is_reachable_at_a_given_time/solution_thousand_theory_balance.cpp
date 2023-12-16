class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        int dx = abs(fx-sx), dy=abs(fy-sy);
        if (dx==0 && dy==0) return t!=1;
        int a = min(dx,dy), b = max(dx,dy);
        return b<=t;
    }
};