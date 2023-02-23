# Sorting:
We implement a custom comparator for the condition "sort by frequency (descending) and for same frequency sort by string (ascending)"
```
bool comp(pair<string,int>a, pair<string,int>b)
{
    if (a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> H;
        for (string w: words) H[w]++;
        vector<pair<string,int>> vec;
        for (auto p: H) vec.push_back({p.first,p.second});
        sort(vec.begin(),vec.end(),comp);
        vector<string>res;
        for (int i=0; i<k; ++i) res.push_back(vec[i].first);
        return res;
    }
};
```
Same thing in Python3. Python has inbuilt `collections.Counter` to get frequency map  from array. Also Python"s sorting API accepts the use of 2 keys if the first key has equal value, hence we need not write a separate comparator function.
```
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counter = Counter(words)
        sorted_words = sorted(counter.keys(), key=lambda i: (-counter[i], i))
        return sorted_words[:k]
```

If you "really" like compact albeit slightly difficult to read code, here is a one-liner for you (though I wont recommend it in real life):
```
def topKFrequent(self, words: List[str], k: int) -> List[str]:
	return [i[0] for i in sorted(Counter(words).items(), key=lambda j: (-j[1],j[0]))][:k]
```

```
TC: O( n log(n))
SC: O(n)
```
# Priority Queue
Instead of sorting we can maintain a priority queue of length K. If length exceeds K, we pop out the last item as per our condition.
```
bool comp(pair<string,int>a, pair<string,int>b)
{
    if (a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> H;
        for (string w: words) H[w]++;
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)*> pq(comp);
        for (auto p: H)
        {
            pq.push({p.first,p.second});
            if (pq.size()>k) pq.pop();
        }
        vector<string>res;
        while (!pq.empty())
        {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }
        return res;
    }
};
```
```
TC: O(n log(K))
SC: O(n)
```
If you have any questions dont hesitate to ask. Please upvote if you find this useful.