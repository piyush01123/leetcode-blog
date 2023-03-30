class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0, mask=0;
        for (int i=31; i>=0; i--)
        {
            mask |= (1<<i);
            int curr = res | (1<<i);
            unordered_set<int> S;
            for (int num: nums) S.insert((num&mask));
            for (int n: S) if (S.find((curr^n))!=S.end()){res=curr; break;}
        }
        return res;
    }
};