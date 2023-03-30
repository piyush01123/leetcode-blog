bool cmpv(vector<int>box1,vector<int>box2)
{
    return box1[1]>box2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmpv);
        int curr=0, res=0;
        for (auto boxType: boxTypes)
        {
            int n=boxType[0], w=boxType[1];
            if (curr+n>=truckSize)
            {
                res += w*(truckSize-curr);
                break;
            }
            curr += n;
            res += w*n;
        }
        return res;
    }
};