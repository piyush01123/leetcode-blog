class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        ds, dt, res = Counter(s), Counter(target), sys.maxsize
        for k,v in dt.items():
            if k not in ds or ds[k]<v: return 0
            res = min(res, ds[k]//v)
        return res
        