class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        Hs, Ht = collections.Counter(s), collections.Counter(t)
        for k in Ht:
            if k not in Hs or Hs[k]<Ht[k]:
                return k