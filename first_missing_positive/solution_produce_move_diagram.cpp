class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> positives;
        int minVal=INT_MAX, maxVal=0;
        for (int n: nums) if (n>0)
        {
            positives.insert(n);
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }
        // cout << "m=" << minVal << " M=" << maxVal << endl;
        if (minVal>1) return 1;
        for (int i=minVal; i<=maxVal; i++) if (positives.find(i)==positives.end()) return i;
        return maxVal+1;
    }
};