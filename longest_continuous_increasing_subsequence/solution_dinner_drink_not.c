

int findLengthOfLCIS(int* nums, int numsSize){
    int res=1, curr=1;
    for (int i=1; i<numsSize; i++)
    {
        if (nums[i]>nums[i-1]) curr++;
        else
        {
            if (curr>res) res=curr;
            curr=1;
        }
    }
    if (curr>res) res=curr;
    return res;
}