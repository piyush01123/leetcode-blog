# @param {Integer[]} nums
# @return {Integer}
def find_length_of_lcis(nums)
    res=1
    curr=1
    n=nums.length
    for i in 1..n-1 do
        if nums[i]>nums[i-1]
            curr = curr+1
        else
            if curr>res
                res=curr
            end
            curr = 1
        end
    end
    if curr>res
        res = curr
    end
    return res
end