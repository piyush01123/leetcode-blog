class Solution {
public:
    void pv(unordered_set<int> comps){for (int k: comps) cout<<k<<',';cout<<endl;}
    int maxOperations(vector<int>& nums, int target) {
        unordered_map<int,int> comps;
        int ctr=0;
        for (int n: nums)
        {
            if (comps.count(n) && comps[n]>0)
            {
                ctr++;
                comps[n]--;
            } else comps[target-n]++;
        }
        return ctr;
    }
};