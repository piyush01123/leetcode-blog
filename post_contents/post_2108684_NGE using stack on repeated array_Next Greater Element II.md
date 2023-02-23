The solution is based on NGE. Except that we repeat the input array twice and return the first n elements as the answer.

First let us solve an easier prolem without the circular thing.
NGE problem for an array
----------------

Consider you have an array. The problem is that for each element in the array find the first element to the right of that element which is larger than it. If there is none output -1.
For example , `A=[2,3,1,4]`. Then output is `{2:3,  3:4,  1:-1,  4:-1}`
HOW DO YOU SOLVE THIS?
Answer is to use a monotonically decreasing stack.  Here is the general strategy
1. Start with appending `A[0]` to the stack.
2. As you traverse the array, if you see that `A[i] <= stack top`, push it to the stack making it the new stack top. Thus you will notice that this results in a monotonically decreasing stack.
2. If ever `A[i]` is greater than the stack top, it means you have found NGE for the number which was at the top of the stack (also the smallest). So pop it and add this pair (`stack top` --> `A[i]`) to your answer. Now check for the new stack top. Continue this till this `A[i]` is the NGE for the stack members.
3. After you are done, only those which are greater or equal to `A[i]` will remain in the stack. Now push `A[i]` to the stack as well.
4. At the end, NGE for all elements which remained in the stack is -1.
```
vector<int> nextGreaterElements(vector<int> nums) {
	int n=nums.size();
	stack<pair<int,int>> S;
	vector<int> res (n,-1);
	
	for (int i=0; i<n; i++)
	{
		while (!S.empty() && nums[i] > S.top().first)
		{
			res[S.top().second] = nums[i];
			S.pop();
		}
		S.push({nums[i],i});
	}
	return res;
}
```

---


Now for the circular array we just repeat the array twice and run the exact same algorithm.

```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; i++) nums.push_back(nums[i]);

        stack<pair<int,int>> S;
        vector<int> res (2*n,-1);
        
        for (int i=0; i<2*n; i++)
        {
            while (!S.empty() && nums[i] > S.top().first)
            {
                res[S.top().second] = nums[i];
                S.pop();
            }
            S.push({nums[i],i});
        }
        return vector<int>(res.begin(), res.begin()+n);
    }
};
```
