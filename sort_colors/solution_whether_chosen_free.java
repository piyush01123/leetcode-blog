class Solution {
    void swap(int[] A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    public void sortColors(int[] nums) 
    {
        int i=0, l=0, r=nums.length-1;
        while (i<=r)
        {
            if (nums[i]==1) i++;
            else if (nums[i]==0) swap(nums, i++, l++);
            else if (nums[i]==2) swap(nums, i, r--);
        }
    }
}