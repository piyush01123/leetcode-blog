class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counter = Counter(words)
        counter = {k:-v for k,v in counter.items()}
        sorted_words = sorted(counter.keys(), key=lambda i: (counter[i], i))
        return sorted_words[:k]