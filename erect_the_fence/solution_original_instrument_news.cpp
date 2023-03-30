int orient(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int ax=a[0], ay=a[1], bx=b[0], by=b[1], cx=c[0], cy=c[1];
    int abx = bx-ax, aby = by-ay, bcx = cx-bx, bcy = cy-by;
    return (abx*bcy) - (bcx*aby);
}
bool cmp(vector<int> a, vector<int>b)
{
    int ax=a[0], ay=a[1], bx=b[0], by=b[1];
    if (ax==bx) return ay<by;
    return ax<bx;
}
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) 
    {
        int n = trees.size();
        sort(trees.begin(), trees.end(), cmp);
        vector<vector<int>> hull;
        for (int i=0; i<n; i++)
        {
            while (hull.size()>=2 && orient(hull[hull.size()-2], hull.back(), trees[i])<0) hull.pop_back();
            hull.push_back(trees[i]);
        }
        // hull.pop_back();
        for (int i=n-1; i>=0; i--)
        {
            while (hull.size()>=2 && orient(hull[hull.size()-2], hull.back(), trees[i])<0) hull.pop_back();
            hull.push_back(trees[i]);
        }
        set<vector<int>> sv;
        for (auto &p: hull) sv.insert(p);
        hull = {};
        for (auto &p: sv) hull.push_back(p);
        return hull;
    }
};