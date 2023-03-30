class Solution {
public:
    void printVec(vector<int>v)
    {
        cout << '{';
        for (int i: v) cout << i << ',';
        cout << '}' << endl;
    }
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSums(n+1,0), rightSums(n+1,0);
        for (int i=1; i<=n; i++) leftSums[i] = leftSums[i-1] + ((nums[i-1]==0)?1:0);
        reverse(nums.begin(), nums.end());
        for (int i=1; i<=n; i++) rightSums[i] = rightSums[i-1] + ((nums[i-1]==1)?1:0);
        reverse(rightSums.begin(), rightSums.end());
        vector<int> totVals(n+1,0);
        for (int i=0; i<=n; i++) totVals[i]=leftSums[i]+rightSums[i];
        int maxVal = *max_element(totVals.begin(), totVals.end());
        vector<int>res;
        for (int i=0; i<=n; i++) if (totVals[i]==maxVal) res.push_back(i);
        return res;
    }
};