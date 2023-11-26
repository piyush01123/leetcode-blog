class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> res;
        int index=0;
        for (int cur=1; cur<=n; cur++)
        {
            res.push_back("Push");
            if (cur==target[index]) index++;
            else res.push_back("Pop");
            if (index==target.size()) return res;
        }
        return {}; //wont come here
    }
};