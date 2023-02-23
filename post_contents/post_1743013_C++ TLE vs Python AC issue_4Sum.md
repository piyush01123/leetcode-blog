I have noticed several times that I am getting TLE while solving a problem in C++. Then when I write the exact same algorithm in python I get an AC. This could be because LC allows more time for python. Does this mean anything? Is it better to switch to python for this reason?

Evidence:
[4-Sum](https://leetcode.com/problems/4sum) throws TLE in C++ for this:
```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                unordered_set<int> S;
                for (int k=j+1; k<n; k++)
                {
                    if (S.count(nums[k])) 
                    {
                        vector<int>quad {nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]};
                        sort(quad.begin(),quad.end());
                        if (find(res.begin(), res.end(), quad)==res.end()) res.push_back(quad);
                    }
                    S.insert(target-nums[i]-nums[j]-nums[k]);
                }
            }
        }
        return res;
    }
};
```
but passes in python for this which is exactly the same.
```
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(n):
            for j in range(i+1,n):
                S = set()
                for k in range(j+1,n):
                    if nums[k] in S:
                        quad = [nums[i],nums[j],nums[k],target-nums[i]-nums[j]-nums[k]]
                        quad.sort()
                        if quad not in res:
                            res.append(quad)
                    S.add(target-nums[i]-nums[j]-nums[k])
        return res
```