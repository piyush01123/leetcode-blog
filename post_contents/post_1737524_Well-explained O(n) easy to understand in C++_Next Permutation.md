Steps:
- Traverse through the array right to left, starting from `n-2` position (`n` is length of array)
- If you find `a[i+1]>a[i]` stop.
- If you reached `i=-1` means array is sorted in decreasing order. Reverse the whole array and return. Else follow next steps
- Now remember that to the right of `i` we have decreasing sorted array (from `i+1` to `n-1`)
- Reverse the array from `i+1` to `n-1` to make it increasing sorted.
- Find the smallest number greater than `a[i]` in this portion and swap with `a[i]`. Remember there will always be at least one number greater than `a[i]` here because when you had stopped traversing, you had `a[i+1]>a[i]`, so at least that `a[i+1]` will still be there, but there still might be another more suitable candidate.
- You are done!

For example
```
A = [9,8,4,8,6,4,3]
```
You will stop at `i=2` because for the first time from right to left, `A[i+1]>A[i]`
Now we see that we have a decreasing sorted array to the right of `i=2`: `[8,6,4,3]`. Reverse this part, so A now becomes:
```
A = [9,8,4,3,4,6,8]
```
Now traverse from `i=3` to end of array to find smallest number greater than `A[2]=4` and swap with `A[2]`. So we will have:
```
A=[9,8,6,3,4,4,8]
```
This is indeed the correct answer.

Coding it up:
```
class Solution {
public:
    void swap(int &a, int&b)
    {
        int t=a;
        a=b;
        b=t;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1) return;
        int n=nums.size(), i;
        for (i=n-2; i>=0; i--)
            if (nums[i+1]>nums[i]) break;
        if (i==-1) {reverse(nums.begin(),nums.end()); return;}
        sort(nums.begin()+i+1, nums.end());
        int j;
        for (j=i+1; j<n; j++) if (nums[j]>nums[i]) break;
        swap(nums[i],nums[j]);
        return;
    }
};
```