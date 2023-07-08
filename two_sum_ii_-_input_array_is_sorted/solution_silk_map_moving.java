class Solution {
    public int[] twoSum(int[] numbers, int target) 
    {
        int lo=0, hi=numbers.length-1;
        while (lo<hi)
        {
            int cur = numbers[lo]+numbers[hi];
            if (cur==target) return new int[]{lo+1,hi+1};
            else if (cur<target) lo++;
            else hi--;
        }
        return new int[]{-1,-1};
    }
}