class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> H = new HashMap<Integer,Integer>();
        for (int i=0; i<nums.length; i++)
            if (H.containsKey(nums[i])) 
                return new int[]{H.get(nums[i]), i};
            else
                H.put(target-nums[i], i);
        return new int[]{-1,-1};
    }
}