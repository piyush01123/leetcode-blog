class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>H;
        unordered_set<int>res;
        for(int n: nums)
        {
            if(H.find(n)==H.end())H[n]=1;
            else H[n]++;
            if (H[n]>nums.size()/3) res.insert(n);
        }
        return vector<int>(res.begin(),res.end());        
    }
};
