class Solution {
    void swap(int[] A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    public void sortColors(int[] nums) 
    {
        int i=0, left=0, right=nums.length-1;
        while (i<=right)
        {
            if (nums[i]==1) i++;
            else if (nums[i]==0) swap(nums, i++, left++);
            else if (nums[i]==2) swap(nums, i, right--);
        }
    }
}