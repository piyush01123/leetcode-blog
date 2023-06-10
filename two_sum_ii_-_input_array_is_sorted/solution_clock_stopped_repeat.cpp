class Solution {
public:
    // vector<int> twoSum(vector<int>& numbers, int target) 
    // {
    //     unordered_map<int,int> comps;
    //     for (int i=0; i<numbers.size(); i++)
    //     {
    //         if (comps.count(numbers[i])) return {comps[numbers[i]]+1,i+1};
    //         comps[target-numbers[i]] = i;
    //     }
    //     return {};
    // }
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int lo=0, hi=numbers.size()-1;
        while (lo<hi)
        {
            int curr = numbers[lo]+numbers[hi];
            if (curr==target) return {lo+1,hi+1};
            else if (curr<target) lo++;
            else hi--;
        }
        return {};
    }
};