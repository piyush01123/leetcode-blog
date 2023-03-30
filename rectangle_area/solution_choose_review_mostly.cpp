class Solution {
public:
    int area(int x1, int y1, int x2, int y2)
    {
        return (x2-x1) * (y2-y1);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area_a = area(ax1,ay1,ax2,ay2);
        int area_b = area(bx1,by1,bx2,by2);        
        bool overlap_x = bx1 < ax2 && bx2 > ax1;
        bool overlap_y = by1 < ay2 && by2 > ay1;
        if (!overlap_x || !overlap_y) return area_a+area_b;
        int cx1 = max(ax1,bx1);
        int cy1 = max(ay1,by1);
        int cx2 = min(ax2,bx2);
        int cy2 = min(ay2,by2);
        int area_c = area(cx1,cy1,cx2,cy2);                
        return area_a + area_b - area_c;
    }
};