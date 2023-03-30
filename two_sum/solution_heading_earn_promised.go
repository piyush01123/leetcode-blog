func twoSum(nums []int, target int) []int {
    H := make(map[int]int)
    for i:=0; i<len(nums); i++ {
        idx, present := H[nums[i]]
        if present {
            res := []int {idx, i}
            return res
        }
        H[target-nums[i]] = i
    }
    return []int{}
}