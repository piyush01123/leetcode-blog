Notice that it is sufficient if you get the first partition. Because the rest of the partitions can be obtained by recursively calling the same function for the remaining part of string.

Here is the code to print the first parition (this is not the solution but this code will help you to understand).
```
vector<int> partitionLabels(string s) 
{
	int n=s.length(), j=n-1;
	while (s[j]!=s[0]) j--;
	for (int i=0; i<=j; i++)
	{
		int jj=n-1;
		while (s[jj]!=s[i]) jj--;
		j = max(j,jj);
	}
	cout << s.substr(0,j+1) << endl;
	return {};
}
```
For `s = ababcbacadefegdehijhklij`, it will print `ababcbaca`
For `s = defegdehijhklij` it will print `defegde`.
For `s = hijhklij` it will print `hijhklij` (same as s).

The way it works is that for each character in the partition we find the maximum index of its occurence. Then the paritition is equal to the maximum of these max-indexes.

Now we just need to find the remaining partitions uising recursion for the remaining part of string.

C++ code:

```
class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> res;
        int n=s.length(), j=n-1;
        while (s[j]!=s[0]) j--;
        for (int i=0; i<=j; i++)
        {
            int jj=n-1;
            while (s[jj]!=s[i]) jj--;
            j = max(j,jj);
        }
        res.push_back(j+1);
        if (j<s.length()-1)
        {
            for (int len: partitionLabels(s.substr(j+1,n)))
                res.push_back(len);
        }
        return res;
    }
};
```