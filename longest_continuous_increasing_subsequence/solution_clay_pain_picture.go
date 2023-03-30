func findLengthOfLCIS(nums []int) int {
        var res=1;
        var curr=1;
        var n = len(nums);
        for i := 1; i < n; i++{
            if (nums[i]>nums[i-1]){
                curr = curr+1;
            } else {
                if (curr>res){
                    res = curr;
                }
                curr = 1;
            }
        }
        if (curr>res){
            res = curr;
        }
        return res;        
}