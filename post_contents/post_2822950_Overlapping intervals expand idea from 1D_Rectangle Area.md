First let us solve the problem in 1D:
**Given Two intervals (a1,a2) and (b1,b2) find if they are overlapping or not**
Well, the answer is they are overlapping if 
```
bool overlap = a1 < b2 && a2 > b1;
```

**What is the length of this overlap?**
Well the length of overlap is
```
int L_overlap= min(a2,b2) - max(a1,b1);
```

**So, what is the total length**
```
int L1 = (a2-a1),   L2 = (b2-b1);
int L_total = (overlap ? L1+L2-L_overlap : L1+L2);
```

Now we will expand this idea to 2D.
The only crucial difference is that the overlap happens only if the overlap condition is met in both X and Y directions.

C++ code:
```
class Solution {
public:
    int area(int x1, int y1, int x2, int y2)
    {
        return (x2-x1) * (y2-y1);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A = area(ax1,ay1,ax2,ay2);
        int B = area(bx1,by1,bx2,by2);        
        bool overlap_x = bx1 < ax2 && bx2 > ax1;
        bool overlap_y = by1 < ay2 && by2 > ay1;
        if (!overlap_x || !overlap_y) return A + B;
        int cx1 = max(ax1,bx1);
        int cy1 = max(ay1,by1);
        int cx2 = min(ax2,bx2);
        int cy2 = min(ay2,by2);
        int C = area(cx1,cy1,cx2,cy2);                
        return A + B - C;
    }
};
```