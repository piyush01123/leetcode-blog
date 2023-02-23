My first attempt was to do alternate from front (first even 0,2,4,.. indices then odd 1,3,5,... indices) ie
`0,1,2,3,4,5` becomes `0,3,1,4,2,5` and `0,1,2,3,4` becomes `0,3,1,4,2`. 
```
void wiggleSort(vector<int>& nums) 
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> arr(n, 0);
    for (int i=0; i<n; i+=2)
        arr[n-1-i] = nums[(n+i)/2]; 
    for (int i=1; i<n; i+=2)
        arr[n-1-i] = nums[i/2];
    nums = arr;
}
```
However this fails for `4,5,5,6` because it will give us `4,5,5,6`. 
Notice however that alternate from back works ie `5,6,4,5` (again even indices R to L then odd indices R to L). A few more tests should tell you that this is a valid algorithm. Hence gives us an AC. However we have to take special care of whether array size is even or odd. 

```
void wiggleSort(vector<int>& nums) 
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> arr(n, 0);
    for (int i=0; i<n; i+=2)
        arr[i] = nums[(n-i)/2 - (n%2==0 ? 1 : 0)];
    for (int i=1; i<n; i+=2)
        arr[i] = nums[n-1-i/2];
    nums = arr;
}
```