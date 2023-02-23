# Algorithm
We have a `statements` matrix of size n by n made up of elements 0,1,2 where 
- `statements[i][j]=1` means `person i` thinks `person j` is good.
- `statements[i][j]=0` means `person i` thinks `person j` is bad.
- `statements[i][j]=2` means `person i` doesnt comment on `person j`.

We also have these conditions:
- Good person speaks truth always
- Bad person can say truth or lie

We want to assign either 1 (for good) and 0 (for bad) to all persons in `0,1,..n-1` such that the `statements` matrix is feasible.

## Pseudocode
Now let us write our pseudocode to validate an assignment:
```
FOR i in 0,..,n-1
	FOR j in 0,..,n-1
			IF person i is good AND person j \u2260  statement of person i on person j
				RETURN False
RETURN True
```
We simply need to run this for all possible assignments and if the assignment is valid we count the number of ones. At the end we return the maximum number of ones out of all valid assignments.

## Bitmask
Now, to use bitmask, let us have some notation:
We have `2^n` ways of doing the assignment (each person can be either good or bad). Let us denote an assignment as a variable caleld `number` which is in the range `[0,2^n-1]`.  If ith digit from left is 1 then in our assignment person i is assigned good and if ith digit from left is 0 then in our assignment person i is assigned bad.
For example say n is 3. The we can have 0,1,2,3,4,5,6,7 as possible assignments.
0 in binary is `000` so means all bad
1 in binary is `001` so means (0,1) are bad and 2 is good
5 in binary is `101` so means (0,2) are good, 1 is bad
and so on.

Now let us write some logic we are gonna use later:
#### How do we find if in our assignment ith person is assigned good or bad?
For exampel say our assignment is 5 ie `101`. Then
- `5 & 4 > 0` means person 0 is assigned 1 ie good
- `5 & 2 == 0` means person 1 is assigned 0 ie bad
- `5 & 1 > 0` means person 2 is assigned  1 ie good

Basically it is just a way of iterating over the binary representation of the number.

Now that we have all the pieces let us write the code:

<iframe src="https://leetcode.com/playground/8LL9m5Nw/shared" frameBorder="0" width="800" height="500"></iframe>

Time complexity: O((n^2 )* (2^n))
Space complexity: O(1)

This solution beats 80% of the solutions in terms of runtime and beats 95% of solutions in terms of memory. Please upvote if you found this helpful.