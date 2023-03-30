#define ll long long
class Solution {
public:
    string getstr(int p, int q){return to_string(p)+' '+to_string(q);}
    void util(int p, int q, unordered_set<string>&S)
    {
        string pq = getstr(p,q);
        if (S.find(pq)==S.end()) S.insert(pq);
        else S.erase(pq);
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x_min=INT_MAX, x_max=INT_MIN, y_min=INT_MAX, y_max=INT_MIN;
        ll area=0;
        unordered_set<string> S;
        for (auto rect: rectangles)
        {
            int x=rect[0], y=rect[1], a=rect[2], b=rect[3];
            x_min = min(x_min, x);
            x_max = max(x_max, a);
            y_min = min(y_min, y);
            y_max = max(y_max, b);
            area += ((ll)(a-x)*(ll)(b-y));
            util(x,y,S);util(a,b,S);util(x,b,S);util(a,y,S);
        }
        ll big_area = ((ll)(x_max-x_min)*(ll)(y_max-y_min));
        string bl=getstr(x_min,y_min), tr=getstr(x_max,y_max), br=getstr(x_max,y_min), tl=getstr(x_min,y_max);
        bool c1 = area==big_area;
        bool c2 = S.find(bl)!=S.end();
        bool c3 = S.find(tr)!=S.end();
        bool c4 = S.find(br)!=S.end();
        bool c5 = S.find(tl)!=S.end();
        bool c6 = S.size()==4;
        return c1&&c2&&c3&&c4&&c5&&c6;
    }
};