class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        long long res = 0;
        for (int i=0; i<k; i++)
        {
            auto it = max_element(gifts.begin(),gifts.end());
            *it = sqrt(*it);
        }
        for (int gift: gifts) res+=gift;
        return res;
    }
};