class Solution {
public:
    int countRotations(vector<int> arr, int low, int high)
    {
        if (high < low) return 0;
        if (high == low) return low;
        int mid = low + (high - low) / 2; /*(low + high)/2;*/
        if (mid < high && arr[mid + 1] < arr[mid])
            return (mid + 1);
        if (mid > low && arr[mid] < arr[mid - 1])
            return mid;
        if (arr[high] > arr[mid])
            return countRotations(arr, low, mid - 1);
        return countRotations(arr, mid + 1, high);
    }

    int search(vector<int>& nums, int target) 
    {
        int pivot = countRotations(nums, 0, nums.size()-1), n=nums.size();
        vector<int>::iterator it;
        if (target < nums[0] || pivot==0)
            it = lower_bound(nums.begin()+pivot, nums.end(), target);
        else
            it = lower_bound(nums.begin(), nums.begin()+pivot, target);
        if (it==nums.end()) return -1;
        if (*it==target) return it-nums.begin();
        return -1;
    }
};