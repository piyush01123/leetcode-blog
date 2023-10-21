class Solution 
{
    List<List<Integer>> res;
    void dfs(int[] nums, int target, int start, List<Integer>cur)
    {
        if (target==0)
        {
            for(int k: cur) System.out.print(" "+k); System.out.print('\n');
            res.add(cur);
            return;
        }
        if (target<0 || start==nums.length) return;
        List<Integer> curClone = new ArrayList<Integer>(cur);;
        cur.add(nums[start]);
        dfs(nums, target-nums[start], start+1, cur);
        start++;
        while(start<nums.length && nums[start]==nums[start-1]) start++;
        dfs(nums, target, start, curClone);
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) 
    {
        Arrays.sort(candidates);
        res = new ArrayList<List<Integer>>();
        List<Integer> cur = new ArrayList<Integer>();
        dfs(candidates, target, 0, cur);
        return res;
    }
}