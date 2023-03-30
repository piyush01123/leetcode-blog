class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        ds = Counter(s)
        dt = Counter(target)
        alist = []
        for k,v in dt.items():
            if k not in ds or ds[k]<v:
                return 0
            alist.append(ds[k]//v)
        return min(alist)
        