Firstly it is not an easy problem by any stretch. You need to know about both monotonic stacks and hashmaps and use them in a correct way.
Here is how I did it:
1. Forget about `nums1`. Solve the NGE (Next Greater Element) problem for `nums2` array and store results in a hashmap
2. Traverse through `nums1` and append result for each element from the hashmap (they will all be present because it is a subset of `nums2`) into an array and finally return this array.

The first part is not obvious just like that. So I will explain

---
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

---

If you get this part, then the other part of question (checking for each item in `nums1`) is very easy. Just check the hashmap you have obtained.

My code has the exact same logic I have given above.
```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> H;
        stack<int>S;
        int n1=nums1.size(), n2=nums2.size();
        for (int i=0; i<n2; i++)
        {
            while (!S.empty() && nums2[i]>S.top())
            {
                H[S.top()] = nums2[i];
                S.pop();
            }
            S.push(nums2[i]);
        }
        while (!S.empty())
        {
            H[S.top()]=-1;
            S.pop();
        }
        // We have solved NGE problem for nums2. Now we do 2nd part
        vector<int>res;
        for (int num: nums1) res.push_back(H[num]);
        return res;
    }
};
```
```
TC: O(N1+N2)
SC: O(N2)
```