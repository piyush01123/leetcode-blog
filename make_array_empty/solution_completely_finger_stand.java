class Solution {
    public long countOperationsToEmptyArray(int[] nums) 
    {
        int n = nums.length;
        long res = n;
        HashMap<Integer,Integer> H = new HashMap<Integer,Integer>();
        for(int i=0; i<n; i++) H.put(nums[i],i);
        Arrays.sort(nums);
        for(int i=1; i<n; i++) if (H.get(nums[i])<H.get(nums[i-1])) res+=(n-i);
        return res;
    }
}