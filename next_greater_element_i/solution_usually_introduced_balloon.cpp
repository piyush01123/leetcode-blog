class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> H;
        stack<int>S;
        int i=0, n1=nums1.size(), n2=nums2.size();
        while (i<n2)
        {
            while (!S.empty() && nums2[i]>S.top())
            {
                H[S.top()] = nums2[i];
                S.pop();
            }
            S.push(nums2[i]);
            i++;
        }
        while (!S.empty())
        {
            H[S.top()]=-1;
            S.pop();
        }
        
        vector<int>res;
        for (int num: nums1) res.push_back(H[num]);
        return res;
    }
};