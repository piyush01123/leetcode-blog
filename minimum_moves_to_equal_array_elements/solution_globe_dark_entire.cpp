class Solution {
public:
    int minMoves(vector<int>& nums) {
        // S' = S + (n-1) * m
        // S' = a * n
        // min(nums) or p + m = a
        // n*(p+m) = S + (n-1)*m
        // m = S-n*p
        int n = nums.size();
        int p = *min_element(nums.begin(),nums.end());
        int S = accumulate(nums.begin(),nums.end(),0);
        return S-n*p;
    }
};