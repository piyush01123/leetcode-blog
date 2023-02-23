We can immediately think of a brute-force $O(n^3)$ solution by checking all subarrays:
```
class Solution {
public:
    bool valid(vector<int>&fruits, int i, int j)
    {
        unordered_set<int> unq_fruits;
        for(int k=i; k<=j; k++) unq_fruits.insert(fruits[k]);
        return (unq_fruits.size()<=2);
    }
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0;
        if(n==1) return 1;
        for (int i=0; i<n; i++) for (int j=i+1; j<n; j++)
            if (valid(fruits,i,j)) res=max(res,j-i+1);
        return res;
    }
};
```
This will give us TLE. We can improve it to $O(n^2)$ by noticing that we do not need to check all subarrays. For any starting index, we only extend a subarray to the right as long as it is valid subarray.
```
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0;
        if(n==1) return 1;
        for (int i=0; i<n; i++)
        {
            int j=i;
            unordered_set<int> unq_fruits;
            while (j<n)
            {
                if (!unq_fruits.count(fruits[j]) && unq_fruits.size()==2) break;
                unq_fruits.insert(fruits[j]);
                j++;
            }
            res = max(res, j-i);
        }
        return res;
    }
};
```
This also gives us TLE. By now we must realize that HashSet will not be enough, we are going to need HashMap. The crucial use of HashMap is we can know exactly at what index the subarray becomes valid.

```
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0, i=0;
        if(n==1) return 1;
        unordered_map<int,int> H;
        for (int j=0; j<n; j++)
        {
            H[fruits[j]]++;
            while(i<n && H.size()>2)
            {
                H[fruits[i]]--;
                if (H[fruits[i]]==0) H.erase(fruits[i]);
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};
```
This is $O(n)$ solution and hence AC. However we can still do a minor improvement: We need not check all valid subarrays, only subarrays longer than the longest valid one we have seen earlier. In this solution, we lose track of the exact `(i,j)` that gives us the answer but the length is what we need. This is still $O(n)$.
```
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0, i=0,j;
        if(n==1) return 1;
        unordered_map<int,int> H;
        for (j=0; j<n; j++)
        {
            H[fruits[j]]++;
            if(i<n && H.size()>2)
            {
                H[fruits[i]]--;
                if (H[fruits[i]]==0) H.erase(fruits[i]);
                i++;
            }
        }
        return (j-i);
    }
};
```