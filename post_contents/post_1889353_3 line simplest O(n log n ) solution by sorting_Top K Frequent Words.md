We need the answer in decreasing order of frequency but increasing order lexicographically. To take both into account we make the frequencies negative and use both in increasing order with desired priority for sorting.

```
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counter = Counter(words)
        sorted_words = sorted(counter.keys(),  key=lambda i: (-counter[i], i))
        return sorted_words[:k]
```
I used python because it has a inbuilt counter. If you are using another language you can use hashmap to create a counter yourself.