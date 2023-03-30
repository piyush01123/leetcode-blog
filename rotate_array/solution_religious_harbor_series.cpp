//a[3] to a[n-1] ==> a[0] to a[n-4]
//a[0] to a[2] ==>  a[n-3] to a[n-1]
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> res  = vector<int>(nums.end()-k, nums.end());
        vector<int> firstN_K = vector<int>(nums.begin(), nums.end()-k);
        res.insert(res.end(), firstN_K.begin(), firstN_K.end());
        nums = res;
    }
};