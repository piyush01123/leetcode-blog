The key idea is to track how many ones and zeros we have seen from the beginning at any point. Let us keep an array that stores how many 1s and 0s we have seen at any point.
So, we start with counter=0 at the left end and then we can keep increase counter when we see 1 and decrease when we see 0. 
So, for `[1,0,0,1,1]`, this will be `[1,0,-1,0,1]`.
Now at any index if we want to find which all previous indexes we can find answers with, the answer is all the numbers which have the same number in this array. However we only want the smallest index to find the longest subarray. So, we don"t need to actully go through the array. We can do better! Let use a hash map to store the min index for the counter. 
Running through the same example, we will have the following hashmap:
The hashmap contains the first index where you achieve any value:
`H={1:0, 0:1, -1:2}`

The candidate answer at any index is `i-H[ctr]`.

One tiny issue is if you think about `H` we have in fact seen 0 even before starting going trough the array. So `H[0]` will always be -1. For example if we later see at `i=5` that `ctr=0` then the possible answer is `5-(-1)`

So, H will actually be:
`H={0:-1, 1:0, , -1:2}`

Now we are ready for coding it up:
```
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ctr=0, res=0, n=nums.size();
        unordered_map<int,int> H;
        H[0]=-1;
        for (int i=0; i<n; i++)
        {
            if (nums[i]==1) ctr++;
            else ctr--;
            if (H.count(ctr)) res = max(res, i-H[ctr]);
            else H[ctr]=i;
        }
        return res;
    }
};
```