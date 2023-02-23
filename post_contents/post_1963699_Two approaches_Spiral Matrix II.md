# Approach1
This approach is based on using min, max for x and y carefully. Basically. You go in cycles of 
```
Increment Y
Increement X
Decrement Y
Decrement X
```
The bounds also have to change so that we traverse the spiral.
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> M(n, vector<int>(n,0));
        int x=0, y=0, curr=1, x_min=0, x_max=n-1, y_min=0, y_max=n-1;
        while (x>x_min||x<x_max||y>y_min||y<y_max)
        {
            while (y<y_max) M[x][y++]=curr++; x_min++;
            while (x<x_max) M[x++][y]=curr++; y_max--;
            while (y>y_min) M[x][y--]=curr++; x_max--;
            while (x>x_min) M[x--][y]=curr++; y_min++;     
        }
        M[x][y]=curr;
        return M;
    }
};
```

```
TC: O(n^2)
SC: O(1)
```

Verdict:
Faster than 100% solutions
Memory less than 90% solutions
# Approach 2
This approach uses an observation:
For N=3 ie 9 elements, we see the pattern `v=[3,2,2,1,1]` (Total 9) ie 3 numbers from Left to Right => then 2 from Top to Bottom ==> then 2 from Right to Left ==> then 1 from Bottom to Top ==> then 1 from Left to Right.
Similarly for N=4 ie 16 elements, the pattern is `v=[4,3,3,2,2,1,1]`.
Similarly for N=5 ie 25 elements we have `v=[5,4,4,3,3,2,2,1,1]`

```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> M(n, vector<int>(n,0));
        vector<int>v;
        for (int i=1;i<n;i++){v.push_back(i);v.push_back(i);} v.push_back(n-1);
        reverse(v.begin(),v.end());
        // 2,2,2,1,1
        int curr=1;
        int x=0,y=0;
        for (int i=0; i<v.size(); i++)
        {
            for (int j=0; j<v[i]; j++)
            {
                M[x][y]=curr;
                curr++;
                if (i%4==0) y++;
                if (i%4==1) x++;
                if (i%4==2) y--;
                if (i%4==3) x--;
            }
        }
        M[x][y]=curr;
        return M;
    }
};
```

```
TC: O(n^2)
SC: O(n)
```

Verdict:
Faster than 100% solutions
Memory less than 30% solutions

