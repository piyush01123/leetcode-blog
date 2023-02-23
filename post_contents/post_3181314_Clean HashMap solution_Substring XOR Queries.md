# Intuition
The idea is to store all (upto 32 digits long) binary substrings of `"s"` in a hashmap and then check the hashmap for each query.

Here is the logic to enumerate all non-zero binary substrings of a string of length 1 to 32:
```
for (int i=0; i<s.length(); i++)
{
    if (s[i]=="0") continue;
    int num = 0;
    for (int j=i; j<min(i+32,s.length()); j++) 
    {
        num = (num<<1) + (s[j]-"0");
        cout << "substring:" << s.substr(i,j-i+1) << ",value:" << num << endl; 
    }
}
```
We just need to expand this logic to also consider the substring `"0"` and also to create a hashmap of `num: [i,j]` instead of just printing. 

The hashmap stores the positions of first instance of a substring.

While querying, we are looking for `query[0]^query[1]` because `a^c=b => c=a^b`. If we find it in hashmap we append its positions to result else append `[-1,-1]`.

# Code
```
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) 
    {
        unordered_map<int, vector<int>> H;
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]=="0")
            {
                if (!H.count(0)) H[0]={i,i}; 
                continue;
            }
            int num = 0;
            for (int j=i; j<min(i+32,(int)s.length()); j++) 
            {
                num = (num<<1)+(s[j]-"0");
                if (!H.count(num)) H[num] = {i,j};
            }
        }
        vector<vector<int>> res;
        for (auto &query: queries)
        {
            int val = query[0]^query[1];
            if (H.count(val)) res.push_back(H[val]);
            else res.push_back({-1,-1});
        }
        return res;
    }
};
```

# Complexity
TC: $O(n+m)$, SC: $O(n+m)$ where $n=\vert s \vert$, $m=\vert Q \vert $

### Note on limits
Actually we can also change the for loop to only consider substrings of upto 30 digits long: `for (int j=i; j<min(i+30,(int)s.length()); j++)`. This is because both `first` and `second` are in the range $[0,10^9]$, we know that $10^9$ in binary is 30 digits long. Hence their XOR can be at max 30 digits long ie their maximum value can be `2^{30}-1`.

In the current solution written above, the hashmap will also contain -ve numbers which is not useful for us but does us no harm. By changing 32 to 30 in the for loop, we can make hashmap a little bit smaller.
