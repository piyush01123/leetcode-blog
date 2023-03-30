class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> arr(n, 0);
        // for (int i=0; i<n; i+=2)
        //     arr[n-1-i] = nums[(n+i)/2]; 
        // for (int i=1; i<n; i+=2)
        //     arr[n-1-i] = nums[i/2];
        for (int i=0; i<n; i+=2)
            arr[i] = nums[(n-i)/2 - (n%2==0 ? 1 : 0)];
        for (int i=1; i<n; i+=2)
            arr[i] = nums[n-1-i/2];
        nums = arr;
    }
};