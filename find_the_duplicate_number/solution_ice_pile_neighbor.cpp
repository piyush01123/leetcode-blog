class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 2(f+a)=f+nc+a ==> f+a=nc, Then (2f+a,f)=>(nc+f,f)
        unordered_set<int>S;
        for (int n: nums)
        {
            if (S.count(n)) return n;
            S.insert(n);
        }
        return -1;
    }
};