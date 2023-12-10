class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int cur=0, n=derived.size();
        for(int item: derived) cur^=item;
        return (cur==0);
    }
};