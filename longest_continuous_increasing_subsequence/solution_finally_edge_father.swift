class Solution {
    func findLengthOfLCIS(_ nums: [Int]) -> Int {
        var res=1, curr=1, n = nums.count;
        for i in 1..<n
        {
            if (nums[i]>nums[i-1]){ curr+=1;}
            else
            {
                if (curr>res) {res=curr;}
                curr=1;
            }
        }
        if (curr>res) {res=curr;}
        return res;            
    }
}