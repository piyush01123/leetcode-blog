HashSet:
```
vector<int> twoSum(vector<int>& numbers, int target) 
{
	unordered_map<int,int> comps;
	for (int i=0; i<numbers.size(); i++)
	{
		if (comps.count(numbers[i])) return {comps[numbers[i]]+1,i+1};
		comps[target-numbers[i]] = i;
	}
	return {};
}
```

Linear search using two pointers:
```
vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int lo=0, hi=numbers.size()-1;
        while (lo<hi)
        {
            int curr = numbers[lo]+numbers[hi];
            if (curr==target) return {lo+1,hi+1};
            else if (curr<target) lo++;
            else hi--;
        }
        return {};
    }
```

Linear traversal + Binary search
```
vector<int> twoSum(vector<int>& numbers, int target) 
    {
        for (int i=0; i<numbers.size(); i++)
        {
            if (i>0 && numbers[i]==numbers[i-1]) continue;
            int tmp = target-numbers[i], lo=i+1, hi=numbers.size()-1;
            while (lo<=hi)
            {
                int mid = lo + (hi-lo)/2;
                if (numbers[mid]==tmp) return {i+1,mid+1};
                else if (numbers[mid]<tmp) lo=mid+1;
                else hi=mid-1;
            }
        }
        return {};
    }
```