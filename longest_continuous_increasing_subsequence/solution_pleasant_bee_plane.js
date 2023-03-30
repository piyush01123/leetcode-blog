/**
 * @param {number[]} nums
 * @return {number}
 */
var findLengthOfLCIS = function(nums) {
        var res=1, curr=1, n = nums.length;
        for (let i=1; i<n; i++)
        {
            if (nums[i]>nums[i-1]) curr++;
            else
            {
                if (curr>res) res=curr;
                curr=1;
            }
        }
        if (curr>res) res=curr;
        return res;    
};