/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    var n = nums.length;
    var dp = Array(n);
    dp.fill(1);
    for(let i=0; i<n; i++)
        {
            for (let j=0; j<i; j++)
                {
                    if (nums[i]>nums[j]){
                        dp[i] = Math.max(dp[i],dp[j]+1);
                    }
                }
        }
    return Math.max(...dp);
};